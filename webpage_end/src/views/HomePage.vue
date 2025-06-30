<template>
  <div class="home-container">
    <header class="header">
      <h1>🌱 碳足迹计算器</h1>
      <div class="user-section">
        <span v-if="user" class="welcome">欢迎，{{ user.username }}！</span>
        <button v-if="user" @click="handleLogout" class="logout-btn">退出登录</button>
        <div v-else class="auth-links">
          <router-link to="/login" class="auth-link">登录</router-link>
          <router-link to="/register" class="auth-link">注册</router-link>
        </div>
      </div>
    </header>

    <main class="main-content">
      <div class="hero-section">
        <h2>计算您的碳足迹，为地球贡献力量</h2>
        <p>通过简单的输入，了解您的日常活动对环境的影响，并获取减少碳排放的建议。</p>
      </div>

      <nav class="feature-nav">
        <router-link to="/calculator" class="feature-card">
          <div class="feature-icon">🧮</div>
          <h3>碳足迹计算器</h3>
          <p>计算您的电力消耗和交通出行产生的碳排放</p>
        </router-link>
        
        <router-link to="/user-info" class="feature-card" v-if="user">
          <div class="feature-icon">👤</div>
          <h3>用户信息</h3>
          <p>查看您的个人信息和碳足迹统计</p>
        </router-link>
        
        <router-link to="/daily-record" class="feature-card" v-if="user">
          <div class="feature-icon">📊</div>
          <h3>每日记录</h3>
          <p>查看您的碳足迹变化趋势</p>
        </router-link>
      </nav>

      <div v-if="!user" class="cta-section">
        <h3>开始您的环保之旅</h3>
        <p>注册账号以保存您的计算记录和查看详细统计</p>
        <router-link to="/register" class="cta-btn">立即注册</router-link>
      </div>
    </main>
  </div>
</template>

<script>
import { mapState, mapActions } from 'vuex';

export default {
  name: 'HomePage',
  computed: {
    ...mapState(['user'])
  },
  methods: {
    ...mapActions(['logout']),
    async handleLogout() {
      try {
        await this.logout();
        this.$router.push('/login');
      } catch (error) {
        console.error('退出登录失败:', error);
      }
    }
  }
};
</script>

<style scoped>
.home-container {
  min-height: 100vh;
  background: transparent;
}

.header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 20px 40px;
  background: transparent;
  box-shadow: 0 2px 10px rgba(0,0,0,0.05);
  color: #333;
}

.header h1 {
  margin: 0;
  font-size: 28px;
  font-weight: 600;
  color: #fff;
}

.user-section {
  display: flex;
  align-items: center;
  gap: 20px;
}

.welcome {
  font-size: 16px;
  font-weight: 500;
}

.logout-btn {
  padding: 8px 16px;
  background: #4CAF50;
  color: white;
  border: none;
  border-radius: 6px;
  cursor: pointer;
  transition: all 0.3s;
}

.logout-btn:hover {
  background: #388E3C;
}

.auth-links {
  display: flex;
  gap: 15px;
}

.auth-link,
.auth-link * {
  color: #fff !important;
}

.auth-link {
  background: #4CAF50;
  color: #fff;
  text-decoration: none;
  padding: 8px 16px;
  border: none;
  border-radius: 6px;
  font-weight: 500;
  transition: all 0.3s;
}

.auth-link:hover {
  background: #388E3C;
  color: #fff;
}

.main-content {
  padding: 60px 40px;
  max-width: 1200px;
  margin: 0 auto;
}

.hero-section {
  text-align: center;
  color: #333;
  margin-bottom: 60px;
  background: transparent;
  padding: 32px 0;
}

.hero-section h2 {
  font-size: 36px;
  margin-bottom: 20px;
  font-weight: 600;
  color: #4CAF50;
}

.hero-section p {
  font-size: 18px;
  color: #4CAF50;
  max-width: 600px;
  margin: 0 auto;
  line-height: 1.6;
}

.feature-nav {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
  gap: 30px;
  margin-bottom: 60px;
  background: transparent !important;
}

.feature-card {
  background: #4CAF50;
  color: #fff;
  padding: 30px;
  border-radius: 16px;
  box-shadow: 0 4px 20px rgba(0, 0, 0, 0.10);
  text-decoration: none;
  border: none;
  transition: all 0.3s;
}

.feature-card h3,
.feature-card p,
.feature-card .feature-icon {
  color: #fff;
}

.feature-card:hover {
  transform: translateY(-5px);
  background: #388E3C;
  box-shadow: 0 8px 30px rgba(0, 0, 0, 0.16);
}

.feature-icon {
  font-size: 48px;
  margin-bottom: 20px;
  text-align: center;
}

.feature-card h3 {
  font-size: 20px;
  margin-bottom: 15px;
  text-align: center;
}

.feature-card p {
  color: #fff;
  line-height: 1.6;
  text-align: center;
  margin: 0;
}

.cta-section {
  text-align: center;
  color: #333;
  background-size: 100% 100%;
  background-position: center;
  background-repeat: no-repeat;
  padding: 40px;
  border-radius: 16px;
  background: transparent;

  background-size: 100% 100%;
  background-position: center;
  background-repeat: no-repeat;
  color: #333;
  text-align: center;
}

.cta-section h3 {
  font-size: 24px;
  margin-bottom: 15px;
  color: #4CAF50;
}

.cta-section p {
  margin-bottom: 25px;
  color: #4CAF50;
}

.cta-btn {
  display: inline-block;
  padding: 15px 30px;
  background: #4CAF50;
  color: white;
  text-decoration: none;
  border-radius: 8px;
  font-weight: 500;
  transition: background 0.3s;
}

.cta-btn:hover {
  background: #388E3C;
}

@media (max-width: 768px) {
  .header {
    flex-direction: column;
    gap: 20px;
    text-align: center;
  }
  
  .main-content {
    padding: 40px 20px;
  }
  
  .hero-section h2 {
    font-size: 28px;
  }
  
  .feature-nav {
    grid-template-columns: 1fr;
  }
}

.feature-group {
  background: transparent !important;
  border: none !important;
}
</style> 