from flask import Flask, request, jsonify
import pymysql
from flask_cors import CORS
from config import DB_HOST, DB_USER, DB_PASSWORD, DB_NAME, DB_PORT, SECRET_KEY, DEBUG
from utils import hash_password, is_valid_email, is_strong_password
import jwt
from datetime import datetime, timedelta
import logging

# 配置日志
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)

app = Flask(__name__)
app.config['SECRET_KEY'] = SECRET_KEY
CORS(app)  # 启用跨域请求

# 数据库连接函数
def get_db_connection():
    try:
        connection = pymysql.connect(
            host=DB_HOST,
            user=DB_USER,
            password=DB_PASSWORD,
            database=DB_NAME,
            port=DB_PORT,
            charset='utf8mb4',
            cursorclass=pymysql.cursors.DictCursor,
            connect_timeout=20  # 使用较长的超时设置
        )
        return connection
    except pymysql.MySQLError as e:
        logger.error(f"数据库连接错误: {e}")
        # 输出更详细的错误信息以便调试
        import traceback
        traceback.print_exc()
        return None
    except Exception as e:
        logger.error(f"未知错误: {e}")
        import traceback
        traceback.print_exc()
        return None

# 生成JWT令牌
def generate_jwt_token(user_id):
    payload = {
        'exp': datetime.utcnow() + timedelta(days=1),  # 令牌有效期1天
        'iat': datetime.utcnow(),
        'sub': user_id
    }
    return jwt.encode(
        payload,
        app.config.get('SECRET_KEY'),
        algorithm='HS256'
    )

# 验证令牌的装饰器
def token_required(f):
    from functools import wraps
    
    @wraps(f)
    def decorated(*args, **kwargs):
        token = None
        # 检查Authorization头
        if 'Authorization' in request.headers:
            auth_header = request.headers['Authorization']
            try:
                token = auth_header.split(" ")[1]  # 提取Bearer token
            except IndexError:
                token = auth_header
                
        if not token:
            return jsonify({'message': '缺少令牌，请登录'}), 401
            
        try:
            # 验证令牌
            payload = jwt.decode(token, app.config['SECRET_KEY'], algorithms=['HS256'])
            user_id = payload['sub']
        except:
            return jsonify({'message': '令牌无效或已过期'}), 401
            
        return f(user_id, *args, **kwargs)
        
    return decorated

# 用户注册API
@app.route('/api/register', methods=['POST'])
def register():
    data = request.get_json()
    username = data.get('username')
    password = data.get('password')
    email = data.get('email')
    
    # 验证输入
    if not username or not password:
        return jsonify({"success": False, "message": "用户名和密码不能为空"}), 400
    
    # 验证邮箱格式
    if email and not is_valid_email(email):
        return jsonify({"success": False, "message": "邮箱格式不正确"}), 400
    
    # 验证密码强度
    if not is_strong_password(password):
        return jsonify({
            "success": False,
            "message": "密码不符合要求：至少8位，包含大小写字母、数字和特殊字符"
        }), 400
    
    # 连接数据库
    conn = get_db_connection()
    if not conn:
        return jsonify({"success": False, "message": "数据库连接失败，请检查数据库配置和连接"}), 500
    
    try:
        cursor = conn.cursor()
        
        # 检查用户名是否已存在
        cursor.execute("SELECT * FROM users WHERE username = %s", (username,))
        if cursor.fetchone():
            return jsonify({"success": False, "message": "用户名已存在"}), 400
        
        # 检查邮箱是否已存在
        if email:
            cursor.execute("SELECT * FROM users WHERE email = %s", (email,))
            if cursor.fetchone():
                return jsonify({"success": False, "message": "邮箱已被注册"}), 400
        
        # 加密密码
        hashed_password = hash_password(password)
        
        # 创建新用户
        cursor.execute(
            "INSERT INTO users (username, password, email) VALUES (%s, %s, %s)",
            (username, hashed_password, email)
        )
        conn.commit()
        
        # 获取新创建的用户ID
        user_id = cursor.lastrowid
        
        # 生成JWT令牌
        token = generate_jwt_token(user_id)
        
        return jsonify({
            "success": True,
            "message": "注册成功",
            "token": token
        }), 201
    
    except Exception as e:
        # 添加详细的错误日志
        import traceback
        logger.error(f"注册过程中出错: {str(e)}")
        logger.error(traceback.format_exc())
        return jsonify({"success": False, "message": f"注册失败: {str(e)}"}), 500
    
    finally:
        if 'conn' in locals() and conn:
            conn.close()

# 用户登录API
@app.route('/api/login', methods=['POST'])
def login():
    data = request.get_json()
    username = data.get('username')
    password = data.get('password')
    
    # 验证输入
    if not username or not password:
        return jsonify({"success": False, "message": "用户名和密码不能为空"}), 400
    
    # 连接数据库
    conn = get_db_connection()
    if not conn:
        return jsonify({"success": False, "message": "数据库连接失败，请检查数据库配置和连接"}), 500
    
    try:
        cursor = conn.cursor()
        
        # 获取用户信息
        cursor.execute("SELECT * FROM users WHERE username = %s", (username,))
        user = cursor.fetchone()
        
        # 验证用户和密码
        if user and user['password'] == hash_password(password):
            # 移除密码信息再返回
            if 'password' in user:
                del user['password']
            
            # 生成JWT令牌
            token = generate_jwt_token(user['id'])
            
            return jsonify({
                "success": True,
                "message": "登录成功",
                "user": user,
                "token": token
            }), 200
        else:
            return jsonify({"success": False, "message": "用户名或密码错误"}), 401
    
    except Exception as e:
        # 添加详细的错误日志
        import traceback
        logger.error(f"登录过程中出错: {str(e)}")
        logger.error(traceback.format_exc())
        return jsonify({"success": False, "message": f"登录失败: {str(e)}"}), 500
    
    finally:
        if 'conn' in locals() and conn:
            conn.close()

# 获取所有用户 (需要token验证)
@app.route('/api/users', methods=['GET'])
@token_required
def get_all_users(current_user_id):
    try:
        conn = get_db_connection()
        if not conn:
            return jsonify({"success": False, "message": "数据库连接失败"}), 500
        
        cursor = conn.cursor()
        cursor.execute("SELECT id, username, email, created_at FROM users")
        users = cursor.fetchall()
        
        return jsonify({"success": True, "users": users}), 200
    
    except Exception as e:
        return jsonify({"success": False, "message": f"获取用户列表失败: {str(e)}"}), 500
    
    finally:
        if 'conn' in locals() and conn:
            conn.close()

# 获取单个用户 (需要token验证)
@app.route('/api/users/<int:user_id>', methods=['GET'])
@token_required
def get_user(current_user_id, user_id):
    try:
        conn = get_db_connection()
        if not conn:
            return jsonify({"success": False, "message": "数据库连接失败"}), 500
        
        cursor = conn.cursor()
        cursor.execute("SELECT id, username, email, created_at FROM users WHERE id = %s", (user_id,))
        user = cursor.fetchone()
        
        if user:
            return jsonify({"success": True, "user": user}), 200
        else:
            return jsonify({"success": False, "message": "用户不存在"}), 404
    
    except Exception as e:
        return jsonify({"success": False, "message": f"获取用户失败: {str(e)}"}), 500
    
    finally:
        if 'conn' in locals() and conn:
            conn.close()

# 获取当前登录用户信息
@app.route('/api/me', methods=['GET'])
@token_required
def get_me(current_user_id):
    try:
        conn = get_db_connection()
        if not conn:
            return jsonify({"success": False, "message": "数据库连接失败"}), 500
        
        cursor = conn.cursor()
        cursor.execute("SELECT id, username, email, created_at FROM users WHERE id = %s", (current_user_id,))
        user = cursor.fetchone()
        
        if user:
            return jsonify({"success": True, "user": user}), 200
        else:
            return jsonify({"success": False, "message": "用户不存在"}), 404
    
    except Exception as e:
        return jsonify({"success": False, "message": f"获取用户信息失败: {str(e)}"}), 500
    
    finally:
        if 'conn' in locals() and conn:
            conn.close()

# 更新用户信息 (需要token验证)
@app.route('/api/users/<int:user_id>', methods=['PUT'])
@token_required
def update_user(current_user_id, user_id):
    # 验证权限：只能更新自己的信息，除非是管理员
    if current_user_id != user_id:
        # 这里可以添加管理员权限检查
        return jsonify({"success": False, "message": "无权限修改其他用户信息"}), 403
    
    data = request.get_json()
    
    try:
        conn = get_db_connection()
        if not conn:
            return jsonify({"success": False, "message": "数据库连接失败"}), 500
        
        cursor = conn.cursor()
        
        # 检查用户是否存在
        cursor.execute("SELECT * FROM users WHERE id = %s", (user_id,))
        if not cursor.fetchone():
            return jsonify({"success": False, "message": "用户不存在"}), 404
        
        # 构建UPDATE语句
        update_fields = []
        values = []
        
        if 'username' in data:
            new_username = data['username']
            # 检查新用户名是否已被使用
            cursor.execute("SELECT * FROM users WHERE username = %s AND id != %s", (new_username, user_id))
            if cursor.fetchone():
                return jsonify({"success": False, "message": "用户名已存在"}), 400
            
            update_fields.append("username = %s")
            values.append(new_username)
        
        if 'email' in data:
            new_email = data['email']
            # 验证邮箱格式
            if not is_valid_email(new_email):
                return jsonify({"success": False, "message": "邮箱格式不正确"}), 400
            
            # 检查邮箱是否已被使用
            cursor.execute("SELECT * FROM users WHERE email = %s AND id != %s", (new_email, user_id))
            if cursor.fetchone():
                return jsonify({"success": False, "message": "邮箱已被注册"}), 400
            
            update_fields.append("email = %s")
            values.append(new_email)
        
        if 'password' in data:
            new_password = data['password']
            # 验证密码强度
            if not is_strong_password(new_password):
                return jsonify({
                    "success": False,
                    "message": "密码不符合要求：至少8位，包含大小写字母、数字和特殊字符"
                }), 400
            
            # 加密新密码
            hashed_password = hash_password(new_password)
            update_fields.append("password = %s")
            values.append(hashed_password)
        
        if not update_fields:
            return jsonify({"success": False, "message": "没有提供要更新的字段"}), 400
        
        # 执行更新
        sql = f"UPDATE users SET {', '.join(update_fields)} WHERE id = %s"
        values.append(user_id)
        
        cursor.execute(sql, tuple(values))
        conn.commit()
        
        return jsonify({"success": True, "message": "用户信息更新成功"}), 200
    
    except Exception as e:
        return jsonify({"success": False, "message": f"更新用户失败: {str(e)}"}), 500
    
    finally:
        if 'conn' in locals() and conn:
            conn.close()

# 删除用户 (需要token验证)
@app.route('/api/users/<int:user_id>', methods=['DELETE'])
@token_required
def delete_user(current_user_id, user_id):
    # 验证权限：只能删除自己的账户，除非是管理员
    if current_user_id != user_id:
        # 这里可以添加管理员权限检查
        return jsonify({"success": False, "message": "无权限删除其他用户"}), 403
    
    try:
        conn = get_db_connection()
        if not conn:
            return jsonify({"success": False, "message": "数据库连接失败"}), 500
        
        cursor = conn.cursor()
        
        # 检查用户是否存在
        cursor.execute("SELECT * FROM users WHERE id = %s", (user_id,))
        if not cursor.fetchone():
            return jsonify({"success": False, "message": "用户不存在"}), 404
        
        # 删除用户
        cursor.execute("DELETE FROM users WHERE id = %s", (user_id,))
        conn.commit()
        
        return jsonify({"success": True, "message": "用户删除成功"}), 200
    
    except Exception as e:
        return jsonify({"success": False, "message": f"删除用户失败: {str(e)}"}), 500
    
    finally:
        if 'conn' in locals() and conn:
            conn.close()

if __name__ == '__main__':
    logger.info("服务器启动中，监听地址为 http://0.0.0.0:5000")
    app.run(debug=DEBUG, host='0.0.0.0', port=5000) 