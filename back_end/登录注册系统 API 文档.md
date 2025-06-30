[TOC]

# 登录注册系统 API 文档

## 基本信息

- **基础URL**: `http://8.138.115.164:5000`
- **内容类型**: `application/json`
- **字符编码**: UTF-8

## 认证方式

除了注册和登录API外，所有API都需要认证。认证方式为Bearer Token认证：

```
Authorization: Bearer <token>
```

## API端点

### 1. 用户注册

- **URL**: `/api/register`
- **方法**: `POST`
- **描述**: 创建新用户账户

**请求参数**:

| 参数名   | 类型   | 必填 | 描述                                                |
| -------- | ------ | ---- | --------------------------------------------------- |
| username | string | 是   | 用户名                                              |
| password | string | 是   | 密码（必须包含大小写字母、数字和特殊字符，至少8位） |
| email    | string | 是   | 用户邮箱                                            |

**请求示例**:
```json
{
  "username": "testuser",
  "password": "Test@1234",
  "email": "test@example.com"
}
```

**响应参数**:

| 参数名  | 类型    | 描述        |
| ------- | ------- | ----------- |
| success | boolean | 是否成功    |
| message | string  | 响应消息    |
| token   | string  | JWT认证令牌 |

**响应示例**:
```json
{
  "success": true,
  "message": "注册成功",
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..."
}
```

**状态码**:
- `201` - 创建成功
- `400` - 请求参数错误
- `500` - 服务器内部错误

### 2. 用户登录

- **URL**: `/api/login`
- **方法**: `POST`
- **描述**: 用户登录并获取认证令牌

**请求参数**:

| 参数名   | 类型   | 必填 | 描述   |
| -------- | ------ | ---- | ------ |
| username | string | 是   | 用户名 |
| password | string | 是   | 密码   |

**请求示例**:
```json
{
  "username": "testuser",
  "password": "Test@1234"
}
```

**响应参数**:

| 参数名  | 类型    | 描述        |
| ------- | ------- | ----------- |
| success | boolean | 是否成功    |
| message | string  | 响应消息    |
| user    | object  | 用户信息    |
| token   | string  | JWT认证令牌 |

**响应示例**:
```json
{
  "success": true,
  "message": "登录成功",
  "user": {
    "id": 1,
    "username": "testuser",
    "email": "test@example.com"
  },
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..."
}
```

**状态码**:
- `200` - 成功
- `400` - 请求参数错误
- `401` - 认证失败
- `500` - 服务器内部错误

### 3. 获取当前用户信息

- **URL**: `/api/me`
- **方法**: `GET`
- **描述**: 获取当前登录用户的信息
- **认证**: 需要Bearer Token

**响应参数**:

| 参数名  | 类型    | 描述     |
| ------- | ------- | -------- |
| success | boolean | 是否成功 |
| user    | object  | 用户信息 |

**响应示例**:
```json
{
  "success": true,
  "user": {
    "id": 1,
    "username": "testuser",
    "email": "test@example.com",
    "created_at": "2025-06-22T13:52:48"
  }
}
```

**状态码**:
- `200` - 成功
- `401` - 未认证或令牌无效
- `500` - 服务器内部错误

### 4. 获取所有用户

- **URL**: `/api/users`
- **方法**: `GET`
- **描述**: 获取所有用户列表
- **认证**: 需要Bearer Token

**响应参数**:

| 参数名  | 类型    | 描述     |
| ------- | ------- | -------- |
| success | boolean | 是否成功 |
| users   | array   | 用户列表 |

**响应示例**:
```json
{
  "success": true,
  "users": [
    {
      "id": 1,
      "username": "testuser",
      "email": "test@example.com"
    },
    {
      "id": 2,
      "username": "anotheruser",
      "email": "another@example.com"
    }
  ]
}
```

**状态码**:
- `200` - 成功
- `401` - 未认证或令牌无效
- `500` - 服务器内部错误

### 5. 获取特定用户

- **URL**: `/api/users/{user_id}`
- **方法**: `GET`
- **描述**: 获取指定ID的用户信息
- **认证**: 需要Bearer Token

**路径参数**:

| 参数名  | 类型    | 描述   |
| ------- | ------- | ------ |
| user_id | integer | 用户ID |

**响应参数**:

| 参数名  | 类型    | 描述     |
| ------- | ------- | -------- |
| success | boolean | 是否成功 |
| user    | object  | 用户信息 |

**响应示例**:
```json
{
  "success": true,
  "user": {
    "id": 1,
    "username": "testuser",
    "email": "test@example.com",
    "created_at": "2025-06-22T13:52:48"
  }
}
```

**状态码**:
- `200` - 成功
- `401` - 未认证或令牌无效
- `404` - 用户不存在
- `500` - 服务器内部错误

### 6. 更新用户信息

- **URL**: `/api/users/{user_id}`
- **方法**: `PUT`
- **描述**: 更新指定ID的用户信息
- **认证**: 需要Bearer Token

**路径参数**:

| 参数名  | 类型    | 描述   |
| ------- | ------- | ------ |
| user_id | integer | 用户ID |

**请求参数**:

| 参数名   | 类型   | 必填 | 描述       |
| -------- | ------ | ---- | ---------- |
| username | string | 否   | 新的用户名 |
| password | string | 否   | 新的密码   |
| email    | string | 否   | 新的邮箱   |

**请求示例**:
```json
{
  "username": "newtestuser",
  "email": "newemail@example.com"
}
```

**响应参数**:

| 参数名  | 类型    | 描述             |
| ------- | ------- | ---------------- |
| success | boolean | 是否成功         |
| message | string  | 响应消息         |
| user    | object  | 更新后的用户信息 |

**响应示例**:
```json
{
  "success": true,
  "message": "用户信息更新成功",
  "user": {
    "id": 1,
    "username": "newtestuser",
    "email": "newemail@example.com"
  }
}
```

**状态码**:
- `200` - 成功
- `400` - 请求参数错误
- `401` - 未认证或令牌无效
- `403` - 权限不足
- `404` - 用户不存在
- `500` - 服务器内部错误

### 7. 删除用户

- **URL**: `/api/users/{user_id}`
- **方法**: `DELETE`
- **描述**: 删除指定ID的用户
- **认证**: 需要Bearer Token

**路径参数**:

| 参数名  | 类型    | 描述   |
| ------- | ------- | ------ |
| user_id | integer | 用户ID |

**响应参数**:

| 参数名  | 类型    | 描述     |
| ------- | ------- | -------- |
| success | boolean | 是否成功 |
| message | string  | 响应消息 |

**响应示例**:
```json
{
  "success": true,
  "message": "用户已成功删除"
}
```

**状态码**:
- `200` - 成功
- `401` - 未认证或令牌无效
- `403` - 权限不足
- `404` - 用户不存在
- `500` - 服务器内部错误

## 错误响应

所有API在发生错误时都会返回一个统一格式的错误响应：

```json
{
  "success": false,
  "message": "错误描述信息"
}
```

## 注意事项

1. 所有需要认证的API必须在请求头中包含有效的JWT令牌
2. 密码必须符合强密码要求：至少8位，包含大小写字母、数字和特殊字符
3. 普通用户只能查看和修改自己的信息