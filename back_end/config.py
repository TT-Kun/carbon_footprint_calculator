# 数据库配置
import os

# 优先使用环境变量，如果没有则使用默认值
DB_HOST = os.environ.get("DB_HOST", "localhost")  # 数据库主机地址
DB_USER = os.environ.get("DB_USER", "root")       # 数据库用户名
DB_PASSWORD = os.environ.get("DB_PASSWORD", "")   # 数据库密码
DB_NAME = os.environ.get("DB_NAME", "user_management")  # 数据库名称
DB_PORT = int(os.environ.get("DB_PORT", 3306))    # 数据库端口
DB_CONNECT_TIMEOUT = int(os.environ.get("DB_CONNECT_TIMEOUT", 20))  # 数据库连接超时时间(秒)

# 应用配置
SECRET_KEY = os.environ.get("SECRET_KEY", "change_me_in_production")  # 用于JWT令牌加密的密钥
DEBUG = os.environ.get("DEBUG", "True").lower() == "true"  # 开发环境下开启调试模式
TOKEN_EXPIRE_DAYS = int(os.environ.get("TOKEN_EXPIRE_DAYS", 1))  # JWT令牌有效期(天)

# API服务器配置
API_HOST = os.environ.get("API_HOST", "0.0.0.0")  # 监听所有网络接口
API_PORT = int(os.environ.get("API_PORT", 5000))  # API服务器端口 