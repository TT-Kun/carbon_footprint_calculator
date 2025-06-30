import pymysql
from config import DB_HOST, DB_USER, DB_PASSWORD, DB_NAME, DB_PORT
import logging

# 配置日志
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def create_database():
    """创建数据库和用户表"""
    # 首先连接到MySQL服务器，不指定数据库名
    try:
        # 连接到MySQL服务器
        connection = pymysql.connect(
            host=DB_HOST,
            user=DB_USER,
            password=DB_PASSWORD,
            port=DB_PORT
        )
        
        with connection.cursor() as cursor:
            # 创建数据库
            cursor.execute(f"CREATE DATABASE IF NOT EXISTS {DB_NAME}")
            cursor.execute(f"USE {DB_NAME}")
            
            # 创建用户表
            cursor.execute("""
            CREATE TABLE IF NOT EXISTS users (
                id INT AUTO_INCREMENT PRIMARY KEY,
                username VARCHAR(50) NOT NULL UNIQUE,
                password VARCHAR(100) NOT NULL,
                email VARCHAR(100),
                created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
            ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
            """)
            
            logger.info(f"数据库 '{DB_NAME}' 和用户表创建成功!")
        
        connection.close()
        return True
        
    except pymysql.MySQLError as e:
        logger.error(f"初始化数据库时出错: {e}")
        return False
    except Exception as e:
        logger.error(f"未知错误: {e}")
        return False

if __name__ == "__main__":
    create_database() 