# 用户管理系统后端API

这是一个基于Python Flask的用户管理系统后端，提供用户注册、登录和CRUD操作，使用MySQL数据库存储用户信息。

## 功能特性

- 用户注册和登录认证
- JWT令牌身份验证
- 用户信息CRUD操作
- RESTful API设计
- 密码加密存储

## 项目结构

```
├── app.py                # 主应用文件，包含所有API端点
├── config.py             # 配置文件，包含数据库和应用配置
├── config.example.py     # 配置文件示例，不包含敏感信息
├── config_local.py       # 本地配置文件（不应提交到Git）
├── init_db.py            # 数据库初始化脚本
├── requirements.txt      # 项目依赖列表
├── test.py               # 简单的API测试脚本
├── utils.py              # 工具函数，如密码加密等
└── .gitignore            # Git忽略文件列表
```

## 环境要求

- Python 3.8+
- MySQL 5.7+

## 安装和配置

1. 克隆仓库：

```bash
git clone <仓库地址>
cd 用户管理系统
```

2. 安装依赖：

```bash
pip install -r requirements.txt
```

3. 配置数据库和应用：

   配置系统支持三种方式（按优先级排序）：
   
   a) **环境变量**（推荐用于生产环境）
   
   ```bash
   # Linux/macOS
   export DB_HOST=your_db_host
   export DB_USER=your_username
   export DB_PASSWORD=your_password
   export DB_NAME=login_user_management
   export SECRET_KEY=your_secret_key
   
   # Windows
   set DB_HOST=your_db_host
   set DB_USER=your_username
   set DB_PASSWORD=your_password
   set DB_NAME=login_user_management
   set SECRET_KEY=your_secret_key
   ```
   
   b) **本地配置文件**（推荐用于开发环境）
   
   复制示例配置文件并修改：
   
   ```bash
   cp config.example.py config_local.py
   # 然后编辑 config_local.py 文件，设置您的本地配置
   ```
   
   c) **默认值**（仅用于快速启动，不推荐用于生产）
   
   config.py 中包含默认值，但不应在生产环境中使用。

4. 初始化数据库：

```bash
python init_db.py
```

## 安全注意事项

- **敏感信息处理**：所有敏感信息（如数据库密码、密钥等）应通过环境变量或本地配置文件提供，不应硬编码在代码中或提交到版本控制系统。
- **config_local.py**：此文件包含本地开发环境的敏感配置，已被添加到 .gitignore，永远不要提交它到 Git。
- **密码存储**：用户密码使用 SHA-256 算法加盐加密存储，不会明文保存。
- **环境变量优先**：系统设计为优先使用环境变量，这使得在容器化环境（如Docker）中更容易安全地配置应用。

## 运行

启动服务器：

```bash
python app.py
```

服务器默认运行在`http://0.0.0.0:5000`。

## API接口

### 用户注册

- URL: `/api/register`
- 方法: `POST`
- 请求体:
  ```json
  {
    "username": "用户名",
    "password": "密码",
    "email": "邮箱"
  }
  ```
- 响应:
  ```json
  {
    "success": true,
    "message": "注册成功",
    "token": "JWT令牌"
  }
  ```

### 用户登录

- URL: `/api/login`
- 方法: `POST`
- 请求体:
  ```json
  {
    "username": "用户名",
    "password": "密码"
  }
  ```
- 响应:
  ```json
  {
    "success": true,
    "message": "登录成功",
    "user": {
      "id": 1,
      "username": "用户名",
      "email": "邮箱",
      "created_at": "创建时间"
    },
    "token": "JWT令牌"
  }
  ```

### 获取当前用户信息

- URL: `/api/me`
- 方法: `GET`
- 请求头:
  ```
  Authorization: Bearer <JWT令牌>
  ```
- 响应:
  ```json
  {
    "success": true,
    "user": {
      "id": 1,
      "username": "用户名",
      "email": "邮箱",
      "created_at": "创建时间"
    }
  }
  ```

### 获取所有用户

- URL: `/api/users`
- 方法: `GET`
- 请求头:
  ```
  Authorization: Bearer <JWT令牌>
  ```
- 响应:
  ```json
  {
    "success": true,
    "users": [
      {
        "id": 1,
        "username": "用户名1",
        "email": "邮箱1",
        "created_at": "创建时间1"
      },
      {
        "id": 2,
        "username": "用户名2",
        "email": "邮箱2",
        "created_at": "创建时间2"
      }
    ]
  }
  ```

### 获取单个用户

- URL: `/api/users/<user_id>`
- 方法: `GET`
- 请求头:
  ```
  Authorization: Bearer <JWT令牌>
  ```
- 响应:
  ```json
  {
    "success": true,
    "user": {
      "id": 1,
      "username": "用户名",
      "email": "邮箱",
      "created_at": "创建时间"
    }
  }
  ```

### 更新用户信息

- URL: `/api/users/<user_id>`
- 方法: `PUT`
- 请求头:
  ```
  Authorization: Bearer <JWT令牌>
  ```
- 请求体:
  ```json
  {
    "username": "新用户名", // 可选
    "email": "新邮箱",     // 可选
    "password": "新密码"   // 可选
  }
  ```
- 响应:
  ```json
  {
    "success": true,
    "message": "用户信息更新成功"
  }
  ```

### 删除用户

- URL: `/api/users/<user_id>`
- 方法: `DELETE`
- 请求头:
  ```
  Authorization: Bearer <JWT令牌>
  ```
- 响应:
  ```json
  {
    "success": true,
    "message": "用户删除成功"
  }
  ```

## 测试

运行测试脚本以验证API功能：

```bash
python test.py
```

## 注意事项

- 生产环境中应使用更强的密钥
- 建议使用HTTPS保护API通信
- 实际部署时应考虑更多的安全措施
- 定期更新密码和密钥
- 配置文件中的敏感信息不应提交到版本控制系统 