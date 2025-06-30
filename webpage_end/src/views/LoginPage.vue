<template>
  <div class="form-container">
    <div class="form-header-wrapper">
      <button type="button" class="home-link-btn" @click="goHome">返回首页</button>
      <h2 class="form-title">登录</h2>
    </div>
    <form @submit.prevent="handleLogin" class="login-form">
      <div class="form-group">
        <label for="username">用户名</label>
        <input 
          id="username"
          v-model="username" 
          type="text" 
          placeholder="请输入用户名" 
          required 
          :disabled="loading"
        />
      </div>
      
      <div class="form-group">
        <label for="password">密码</label>
        <input 
          id="password"
          v-model="password" 
          type="password" 
          placeholder="请输入密码" 
          required 
          :disabled="loading"
        />
      </div>
      
      <div v-if="error" class="error-message">
        {{ error }}
      </div>
      
      <button type="submit" :disabled="loading || !username || !password" class="submit-btn">
        <span v-if="loading">登录中...</span>
        <span v-else>登录</span>
      </button>
    </form>
    
    <div class="form-footer">
      <router-link to="/register" class="link">没有账号？立即注册</router-link>
    </div>
  </div>
</template>

<script>
import { mapActions } from 'vuex';

export default {
  name: 'LoginPage',
  data() {
    return {
      username: '',
      password: '',
      loading: false,
      error: ''
    };
  },
  methods: {
    ...mapActions(['login']),
    async handleLogin() {
      this.loading = true;
      this.error = '';
      
      try {
        await this.login({ 
          username: this.username, 
          password: this.password 
        });
        this.$router.push('/');
      } catch (error) {
        this.error = error.message || '登录失败，请重试';
      } finally {
        this.loading = false;
      }
    },
    goHome() {
      this.$router.push('/');
    }
  }
};
</script>

<style scoped>
.form-container {
  max-width: 400px;
  margin: 50px auto;
  padding: 30px;
  background: rgba(255,255,255,0.7);
  backdrop-filter: blur(10px);
  border-radius: 12px;
  box-shadow: none;
}

.form-header-wrapper {
  position: relative;
  margin-bottom: 30px;
  height: 40px;
}

.form-title {
  text-align: center;
  font-size: 24px;
  color: #333;
  margin: 0;
  line-height: 40px;
}

.form-group {
  margin-bottom: 20px;
}

label {
  display: block;
  margin-bottom: 8px;
  color: #555;
  font-weight: 500;
}

input {
  width: 100%;
  padding: 12px 16px;
  border: 2px solid #e1e5e9;
  border-radius: 8px;
  font-size: 16px;
  transition: border-color 0.3s;
  box-sizing: border-box;
}

input:focus {
  outline: none;
  border-color: #4CAF50;
}

input:disabled {
  background-color: #f5f5f5;
  cursor: not-allowed;
}

.error-message {
  background: #ffebee;
  color: #c62828;
  padding: 12px;
  border-radius: 6px;
  margin-bottom: 20px;
  font-size: 14px;
}

.submit-btn {
  width: 100%;
  padding: 14px;
  background: #4CAF50;
  color: white;
  border: none;
  border-radius: 8px;
  font-size: 16px;
  font-weight: 500;
  cursor: pointer;
  transition: background-color 0.3s;
}

.submit-btn:hover:not(:disabled) {
  background: #388E3C;
}

.submit-btn:disabled {
  background: #ccc;
  cursor: not-allowed;
}

.form-footer {
  text-align: center;
  margin-top: 20px;
  padding-top: 20px;
  border-top: 1px solid #eee;
}

.link {
  color: #4CAF50;
  text-decoration: none;
  font-weight: 500;
}

.link:hover {
  text-decoration: underline;
}

.home-link-btn {
  position: absolute;
  right: 0;
  top: 0;
  background: #4CAF50;
  border: none;
  color: #fff;
  font-size: 15px;
  font-weight: 500;
  cursor: pointer;
  border-radius: 8px;
  padding: 8px 20px;
  box-shadow: 0 2px 8px rgba(76,175,80,0.08);
  transition: background 0.2s;
  z-index: 10;
}

.home-link-btn:hover {
  background: #388E3C;
  color: #fff;
}
</style>
