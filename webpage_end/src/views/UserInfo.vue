<template>
  <div class="user-profile">
    <header class="profile-header">
      <h1>👤 用户信息</h1>
      <button @click="$router.push('/')" class="back-btn">返回首页</button>
    </header>

    <div v-if="user" class="profile-content">
      <div class="profile-section">
        <h2>基本信息</h2>
        <div class="info-grid">
          <div class="info-item">
            <label>用户名:</label>
            <span>{{ user.username }}</span>
          </div>
          <div class="info-item">
            <label>邮箱:</label>
            <span>{{ user.email }}</span>
          </div>
        </div>
      </div>

      <div class="stats-section">
        <h2>碳足迹统计</h2>
        <div class="stats-grid">
          <div class="stat-card">
            <div class="stat-icon">📊</div>
            <div class="stat-label">本周排放</div>
            <div class="stat-value">{{ weeklyTotal }} kgCO₂</div>
          </div>
          
          <div class="stat-card">
            <div class="stat-icon">📅</div>
            <div class="stat-label">平均每日</div>
            <div class="stat-value">{{ averageDaily }} kgCO₂</div>
          </div>
          
          <div class="stat-card">
            <div class="stat-icon">🎯</div>
            <div class="stat-label">总计算次数</div>
            <div class="stat-value">{{ totalCalculations }}</div>
          </div>
          
          <div class="stat-card">
            <div class="stat-icon">🌍</div>
            <div class="stat-label">平均排放</div>
            <div class="stat-value">{{ averageEmission.toFixed(1) }} kgCO₂</div>
            <div class="stat-subtitle">/每次计算</div>
          </div>
        </div>
      </div>

      <div class="actions-section">
        <h2>快捷操作</h2>
        <div class="action-buttons">
          <router-link to="/calculator" class="action-btn primary">
            🧮 重新计算
          </router-link>
          <router-link to="/daily-record" class="action-btn secondary">
            📊 查看图表
          </router-link>
          <button @click="clearHistory" class="action-btn danger">
            🗑️ 清空历史
          </button>
        </div>
      </div>
    </div>
    
    <div v-else class="no-user">
      <div class="no-user-content">
        <div class="no-user-icon">🔒</div>
        <h2>请先登录</h2>
        <p>登录后可以查看您的个人信息和碳足迹统计</p>
        <router-link to="/login" class="login-btn">立即登录</router-link>
      </div>
    </div>
  </div>
</template>

<script>
import { mapState, mapGetters, mapMutations } from 'vuex';
import { getMe } from '@/api/user';

export default {
  name: 'UserInfo',
  computed: {
    ...mapState(['user']),
    ...mapGetters(['weeklyData', 'totalCalculations', 'averageEmission']),
    weeklyTotal() {
      return this.weeklyData.reduce((a, b) => a + b, 0).toFixed(1);
    },
    averageDaily() {
      const total = this.weeklyData.reduce((a, b) => a + b, 0);
      return (total / 7).toFixed(1);
    }
  },
  methods: {
    ...mapMutations(['CLEAR_CALCULATIONS', 'SET_USER']),
    clearHistory() {
      if (confirm('确定要清空所有计算历史吗？此操作不可恢复。')) {
        this.CLEAR_CALCULATIONS();
      }
    },
    async fetchUser() {
      try {
        const res = await getMe();
        if (res.data.success) {
          this.SET_USER(res.data.user);
        }
      } catch (e) {
        // token 失效等情况
        this.SET_USER(null);
      }
    }
  },
  mounted() {
    this.fetchUser();
  }
}
</script>

<style scoped>
.user-profile {
  max-width: 1000px;
  margin: 0 auto;
  padding: 40px 20px;
}

.profile-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 30px;
  padding-bottom: 20px;
  border-bottom: 2px solid #f0f0f0;
}

.profile-header h1 {
  margin: 0;
  color: #fff;
  font-size: 28px;
}

.back-btn {
  padding: 10px 20px;
  background: #4CAF50;
  color: white;
  border: none;
  border-radius: 6px;
  cursor: pointer;
  transition: background 0.3s;
}

.back-btn:hover {
  background: #388E3C;
}

.profile-section, .stats-section, .actions-section {
  background-size: 100% 100%;
  background-image: url('https://blog.visitacostadelsol.com/hs-fs/hubfs/b-1%20feb%2023-1.png?width=1800&height=1013&name=b-1%20feb%2023-1.png');
  background-position: center;
  background-repeat: no-repeat;
  background: rgba(255,255,255,0.7);
  backdrop-filter: blur(10px);
  border-radius: 12px;
  padding: 25px;
  margin-bottom: 25px;
  box-shadow: none;
}

.profile-section h2, .stats-section h2, .actions-section h2 {
  margin-top: 0;
  margin-bottom: 20px;
  color: #333;
  font-size: 20px;
}

.info-grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
  gap: 20px;
}

.info-item {
  padding: 15px;
  background: #f8f9fa;
  border-radius: 8px;
  border-left: 4px solid #4CAF50;
}

.info-item label {
  display: block;
  font-weight: 600;
  color: #666;
  margin-bottom: 5px;
  font-size: 14px;
}

.info-item span {
  color: #333;
  font-size: 16px;
}

.stats-grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
  gap: 20px;
}

.stat-card {
  padding: 25px;
  background: linear-gradient(135deg, #4CAF50, #45a049);
  color: white;
  border-radius: 12px;
  text-align: center;
  transition: transform 0.3s;
}

.stat-card:hover {
  transform: translateY(-3px);
}

.stat-icon {
  font-size: 32px;
  margin-bottom: 10px;
}

.stat-label {
  font-size: 14px;
  opacity: 0.9;
  margin-bottom: 8px;
}

.stat-value {
  font-size: 24px;
  font-weight: bold;
  margin-bottom: 5px;
}

.stat-subtitle {
  font-size: 12px;
  opacity: 0.8;
}

.action-buttons {
  display: flex;
  gap: 15px;
  flex-wrap: wrap;
}

.action-btn {
  padding: 12px 24px;
  border-radius: 8px;
  text-decoration: none;
  font-weight: 500;
  transition: all 0.3s;
  border: none;
  cursor: pointer;
  font-size: 14px;
}

.action-btn.primary {
  background: #4CAF50;
  color: white;
}

.action-btn.primary:hover {
  background: #388E3C;
}

.action-btn.secondary {
  background: #2196F3;
  color: white;
}

.action-btn.secondary:hover {
  background: #1976D2;
}

.action-btn.danger {
  background: #f44336;
  color: white;
}

.action-btn.danger:hover {
  background: #d32f2f;
}

.no-user {
  display: flex;
  justify-content: center;
  align-items: center;
  min-height: 400px;
}

.no-user-content {
  text-align: center;
  background-size: 100% 100%;
  background-image: url('https://blog.visitacostadelsol.com/hs-fs/hubfs/b-1%20feb%2023-1.png?width=1800&height=1013&name=b-1%20feb%2023-1.png');
  background-position: center;
  background-repeat: no-repeat;
  background: rgba(255,255,255,0.7);
  backdrop-filter: blur(10px);
  padding: 40px;
  border-radius: 12px;
  box-shadow: none;
}

.no-user-icon {
  font-size: 64px;
  margin-bottom: 20px;
}

.no-user-content h2 {
  margin-bottom: 15px;
  color: #333;
}

.no-user-content p {
  color: #666;
  margin-bottom: 25px;
}

.login-btn {
  display: inline-block;
  padding: 12px 30px;
  background: #4CAF50;
  color: white;
  text-decoration: none;
  border-radius: 8px;
  font-weight: 500;
  transition: background 0.3s;
}

.login-btn:hover {
  background: #388E3C;
}

@media (max-width: 768px) {
  .profile-header {
    flex-direction: column;
    gap: 15px;
    text-align: center;
  }
  
  .stats-grid {
    grid-template-columns: 1fr;
  }
  
  .action-buttons {
    flex-direction: column;
  }
  
  .action-btn {
    text-align: center;
  }
}
</style> 