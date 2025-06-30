import hashlib
import uuid
import re

def hash_password(password):
    """
    使用SHA-256算法对密码进行加密
    """
    # 添加盐值
    salt = "user_management_salt"
    password_hash = hashlib.sha256((password + salt).encode()).hexdigest()
    return password_hash

def is_valid_email(email):
    """
    验证邮箱格式是否有效
    """
    email_pattern = r'^[\w\.-]+@[\w\.-]+\.\w+$'
    return re.match(email_pattern, email) is not None

def is_strong_password(password):
    """
    检查密码强度
    要求：至少8位，包含大小写字母、数字和特殊字符
    """
    if len(password) < 8:
        return False
    
    # 检查是否包含大写字母
    if not any(char.isupper() for char in password):
        return False
    
    # 检查是否包含小写字母
    if not any(char.islower() for char in password):
        return False
    
    # 检查是否包含数字
    if not any(char.isdigit() for char in password):
        return False
    
    # 检查是否包含特殊字符
    special_chars = '!@#$%^&*()-_=+[]{}|;:,.<>?/~`"\'\\' 
    if not any(char in special_chars for char in password):
        return False
    
    return True

def generate_token():
    """
    生成一个唯一的令牌，可用于会话管理或密码重置
    """
    return uuid.uuid4().hex 