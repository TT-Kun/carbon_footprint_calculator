import requests
import json
import time

# API基础URL
API_BASE_URL = "http://localhost:5000/api"

def test_register():
    """测试用户注册API"""
    print("\n测试注册API...")
    data = {
        "username": f"testuser_{int(time.time())}",  # 使用时间戳避免用户名重复
        "email": f"test_{int(time.time())}@example.com",
        "password": "Test123!"
    }
    
    print(f"请求数据: {data}")
    
    try:
        response = requests.post(f"{API_BASE_URL}/register", json=data, timeout=20)
        print(f"状态码: {response.status_code}")
        
        try:
            json_response = response.json()
            print(f"响应内容: {json.dumps(json_response, indent=2, ensure_ascii=False)}")
            return json_response.get('token'), data['username'], data['password']
        except:
            print(f"响应内容(无法解析为JSON): {response.text}")
            return None, data['username'], data['password']
    except Exception as e:
        print(f"请求错误: {str(e)}")
        return None, data['username'], data['password']

def test_login(username, password):
    """测试用户登录API"""
    print("\n测试登录API...")
    data = {
        "username": username,
        "password": password
    }
    
    print(f"请求数据: {data}")
    
    try:
        response = requests.post(f"{API_BASE_URL}/login", json=data, timeout=20)
        print(f"状态码: {response.status_code}")
        
        try:
            json_response = response.json()
            print(f"响应内容: {json.dumps(json_response, indent=2, ensure_ascii=False)}")
            return json_response.get('token')
        except:
            print(f"响应内容(无法解析为JSON): {response.text}")
            return None
    except Exception as e:
        print(f"请求错误: {str(e)}")
        return None

if __name__ == "__main__":
    print("===== API简单测试 =====")
    
    # 1. 测试注册
    register_token, username, password = test_register()
    register_success = register_token is not None
    
    # 2. 使用注册的用户测试登录
    login_token = None
    if register_success:
        print("\n使用注册成功的用户进行登录测试...")
        login_token = test_login(username, password)
    else:
        print("\n注册失败，跳过登录测试")
    
    # 3. 测试结果
    if register_success and login_token:
        print("\n测试完全成功! 注册和登录都获取到有效令牌")
    elif register_success:
        print("\n注册成功但登录失败!")
    elif login_token:
        print("\n注册失败但登录成功，这是意外情况!")
    else:
        print("\n测试失败! 注册和登录均未获取到有效令牌") 