<template>
  <div class="daily-record">
    <header class="record-header">
      <h1>📊 每日碳足迹记录</h1>
      <button @click="$router.push('/')" class="back-btn">返回首页</button>
    </header>

    <div v-if="user" class="record-content">
      <div class="chart-section">
        <h2>本周碳足迹趋势</h2>
        <div class="chart-container">
          <bar-chart :data="weeklyData" :labels="weekLabels"></bar-chart>
        </div>
      </div>

      <div class="summary-section">
        <h2>数据摘要</h2>
        <div class="summary-grid">
          <div class="summary-card">
            <div class="summary-icon">📈</div>
            <div class="summary-label">本周总计</div>
            <div class="summary-value">{{ weeklyTotal }} kgCO₂</div>
          </div>
          
          <div class="summary-card">
            <div class="summary-icon">🔼</div>
            <div class="summary-label">最高单日</div>
            <div class="summary-value">{{ maxDaily }} kgCO₂</div>
          </div>
          
          <div class="summary-card">
            <div class="summary-icon">🔽</div>
            <div class="summary-label">最低单日</div>
            <div class="summary-value">{{ minDaily }} kgCO₂</div>
          </div>
          
          <div class="summary-card">
            <div class="summary-icon">🎯</div>
            <div class="summary-label">平均每日</div>
            <div class="summary-value">{{ averageDaily }} kgCO₂</div>
          </div>
        </div>
      </div>

      <div class="history-section">
        <h2>历史记录</h2>
        <div v-if="calculations.length > 0" class="history-list">
          <div v-for="(calc, index) in recentCalculations" :key="index" class="history-item">
            <div class="history-date">{{ formatDate(calc.timestamp) }}</div>
            <div class="history-details">
              <div class="history-total">{{ calc.total.toFixed(2) }} kgCO₂</div>
              <div class="history-breakdown">
                <span>电力: {{ calc.energy.toFixed(2) }} kgCO₂</span>
                <span>交通: {{ calc.transport.toFixed(2) }} kgCO₂</span>
                <span>饮食: {{ (calc.food || 0).toFixed(2) }} kgCO₂</span>
              </div>
            </div>
          </div>
        </div>
        <div v-else class="no-history">
          <div class="no-history-icon">📝</div>
          <p>暂无计算记录</p>
          <router-link to="/calculator" class="calc-btn">开始计算</router-link>
        </div>
      </div>
    </div>
    
    <div v-else class="no-user">
      <div class="no-user-content">
        <div class="no-user-icon">🔒</div>
        <h2>请先登录</h2>
        <p>登录后可以查看您的碳足迹记录和统计图表</p>
        <router-link to="/login" class="login-btn">立即登录</router-link>
      </div>
    </div>
  </div>
</template>

<script>
import { mapState, mapGetters } from 'vuex';
import BarChart from '../components/BarChart.vue';

export default {
  name: 'DailyRecord',
  components: {
    BarChart
  },
  computed: {
    ...mapState(['user', 'calculations']),
    ...mapGetters(['weeklyData']),
    weekLabels() {
      return ['周一', '周二', '周三', '周四', '周五', '周六', '周日'];
    },
    weeklyTotal() {
      return this.weeklyData.reduce((a, b) => a + b, 0).toFixed(1);
    },
    maxDaily() {
      const max = Math.max(...this.weeklyData);
      return max > 0 ? max.toFixed(1) : '0.0';
    },
    minDaily() {
      const filtered = this.weeklyData.filter(val => val > 0);
      const min = filtered.length > 0 ? Math.min(...filtered) : 0;
      return min.toFixed(1);
    },
    averageDaily() {
      const total = this.weeklyData.reduce((a, b) => a + b, 0);
      return (total / 7).toFixed(1);
    },
    recentCalculations() {
      return this.calculations
        .slice()
        .reverse()
        .slice(0, 10);
    }
  },
  methods: {
    formatDate(timestamp) {
      const date = new Date(timestamp);
      return date.toLocaleDateString('zh-CN', {
        year: 'numeric',
        month: 'short',
        day: 'numeric',
        hour: '2-digit',
        minute: '2-digit'
      });
    }
  }
};
</script>

<style scoped>
.daily-record {
  max-width: 1200px;
  margin: 0 auto;
  padding: 40px 20px;
}

.record-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 30px;
  padding-bottom: 20px;
  border-bottom: 2px solid #f0f0f0;
}

.record-header h1 {
  margin: 0;
  color: white;
  font-size: 28px;
}

.back-btn {
  padding: 10px 20px;
  background:#4CAF50;
  color: white;
  border: none;
  border-radius: 6px;
  cursor: pointer;
  transition: background 0.3s;
}

.back-btn:hover {
  background: #5a6268;
}

.record-content {
  display: grid;
  gap: 30px;
}

.chart-section, .summary-section, .history-section {
  background-size: 100% 100%;
  background-image: url('https://blog.visitacostadelsol.com/hs-fs/hubfs/b-1%20feb%2023-1.png?width=1800&height=1013&name=b-1%20feb%2023-1.png');
  background: rgba(255,255,255,0.7);
  backdrop-filter: blur(10px);
  border-radius: 12px;
  padding: 25px;
  box-shadow: none;
}

.chart-section h2, .summary-section h2, .history-section h2 {
  margin-top: 0;
  margin-bottom: 20px;
  color: #333;
  font-size: 20px;
}

.chart-container {
  height: 400px;
  position: relative;
}

.summary-grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
  gap: 20px;
}

.summary-card {
  padding: 20px;
  background: #f8f9fa;
  border-radius: 12px;
  text-align: center;
  transition: transform 0.3s;
  border: 1px solid #eef0f2;
}

.summary-card:hover {
  transform: translateY(-3px);
}

.summary-icon {
  font-size: 24px;
  margin-bottom: 10px;
  color: #4CAF50;
}

.summary-label {
  font-size: 14px;
  color: #666;
  margin-bottom: 8px;
}

.summary-value {
  font-size: 20px;
  font-weight: bold;
  color: #333;
}

.history-list {
  max-height: 400px;
  overflow-y: auto;
}

.history-item {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 15px;
  border-bottom: 1px solid #f0f0f0;
  transition: background 0.3s;
}

.history-item:hover {
  background: #f8f9fa;
}

.history-item:last-child {
  border-bottom: none;
}

.history-date {
  color: #666;
  font-size: 14px;
  min-width: 120px;
}

.history-details {
  text-align: right;
}

.history-total {
  font-size: 16px;
  font-weight: bold;
  color: #333;
  margin-bottom: 5px;
}

.history-breakdown {
  font-size: 12px;
  color: #666;
}

.history-breakdown span {
  margin-left: 15px;
}

.no-history {
  text-align: center;
  padding: 40px;
  color: #666;
}

.no-history-icon {
  font-size: 48px;
  margin-bottom: 15px;
}

.calc-btn {
  display: inline-block;
  margin-top: 15px;
  padding: 10px 20px;
  background: #4CAF50;
  color: white;
  text-decoration: none;
  border-radius: 6px;
  transition: background 0.3s;
}

.calc-btn:hover {
  background: #388E3C;
}

.no-user {
  display: flex;
  justify-content: center;
  align-items: center;
  min-height: 400px;
}

.no-user-content {
  text-align: center;
  background: white;
  padding: 40px;
  border-radius: 12px;
  box-shadow: 0 2px 12px rgba(0,0,0,0.1);
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
  .record-header {
    flex-direction: column;
    gap: 15px;
    text-align: center;
  }
  
  .summary-grid {
    grid-template-columns: 1fr;
  }
  
  .history-item {
    flex-direction: column;
    align-items: flex-start;
    gap: 10px;
  }
  
  .history-date {
    min-width: auto;
  }
  
  .history-details {
    text-align: left;
  }
}
</style> 