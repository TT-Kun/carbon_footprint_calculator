import axios from 'axios';

const BASE_URL = 'http://8.138.115.164:5000';

const instance = axios.create({
  baseURL: BASE_URL,
  headers: {
    'Content-Type': 'application/json',
  },
});

// 请求拦截器：自动携带 token
instance.interceptors.request.use(config => {
  const token = localStorage.getItem('token');
  if (token) {
    config.headers.Authorization = `Bearer ${token}`;
  }
  return config;
}, error => Promise.reject(error));

// 用户注册
export function register(data) {
  return instance.post('/api/register', data);
}

// 用户登录
export function login(data) {
  return instance.post('/api/login', data);
}

// 获取当前用户信息
export function getMe() {
  return instance.get('/api/me');
}

// 获取所有用户
export function getAllUsers() {
  return instance.get('/api/users');
}

// 获取特定用户
export function getUserById(userId) {
  return instance.get(`/api/users/${userId}`);
}

// 更新用户信息
export function updateUser(userId, data) {
  return instance.put(`/api/users/${userId}`, data);
}

// 删除用户
export function deleteUser(userId) {
  return instance.delete(`/api/users/${userId}`);
} 