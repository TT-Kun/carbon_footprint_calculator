<template>
  <div class="form-container">
    <h2>注册</h2>
    <form @submit.prevent="handleRegister" class="register-form">
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
        <label for="email">邮箱</label>
        <input 
          id="email"
          v-model="email" 
          type="email" 
          placeholder="请输入邮箱" 
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
          minlength="8"
        />
      </div>
      
      <div class="form-group">
        <label for="confirmPassword">确认密码</label>
        <input 
          id="confirmPassword"
          v-model="confirmPassword" 
          type="password" 
          placeholder="请再次输入密码" 
          required 
          :disabled="loading"
        />
      </div>
      
      <div v-if="error" class="error-message">
        {{ error }}
      </div>
      
      <button type="submit" :disabled="loading || !isFormValid" class="submit-btn">
        <span v-if="loading">注册中...</span>
        <span v-else>注册</span>
      </button>
    </form>
    
    <div class="form-footer">
      <router-link to="/login" class="link">已有账号？立即登录</router-link>
    </div>
  </div>
</template>

<script>
import { mapActions } from 'vuex';

export default {
  name: 'RegisterPage',
  data() {
    return {
      username: '',
      email: '',
      password: '',
      confirmPassword: '',
      loading: false,
      error: ''
    };
  },
  computed: {
    isFormValid() {
      return this.username && 
             this.email && 
             this.password && 
             this.confirmPassword && 
             this.password === this.confirmPassword &&
             this.password.length >= 8;
    }
  },
  methods: {
    ...mapActions(['register']),
    async handleRegister() {
      if (this.password !== this.confirmPassword) {
        this.error = '两次输入的密码不一致';
        return;
      }
      
      if (this.password.length < 8) {
        this.error = '密码长度至少8位';
        return;
      }
      
      this.loading = true;
      this.error = '';
      
      try {
        await this.register({ 
          username: this.username,
          email: this.email, 
          password: this.password 
        });
        this.$router.push('/');
      } catch (error) {
        this.error = error.message || '注册失败，请重试';
      } finally {
        this.loading = false;
      }
    }
  }
};
</script>

<style scoped>
.form-container {
  max-width: 400px;
  margin: 50px auto;
  padding: 30px;
  background: white;
  border-radius: 12px;
  box-shadow: 0 4px 20px rgba(0,0,0,0.1);
}

h2 {
  text-align: center;
  color: #333;
  margin-bottom: 30px;
  font-size: 24px;
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
</style>
