<template>
  <div class="calculator-container">
    <header class="calculator-header">
      <h1>🧮 碳足迹计算器</h1>
      <button @click="$router.push('/')" class="back-btn">返回首页</button>
    </header>

    <form @submit.prevent="calculate" class="calculator-form">
      <div class="form-section">
        <h2>电力消耗</h2>
        <div class="input-group">
          <label for="energy">电力消耗 (kWh)</label>
          <input 
            id="energy"
            v-model.number="energyUsage" 
            type="number" 
            placeholder="例如: 150"
            step="0.1" 
            required
            min="0"
          >
        </div>
      </div>

      <div class="form-section">
        <h2>交通方式</h2>
        <div v-if="transportModes.length === 0" class="empty-transport">
          <p>请添加您的交通方式</p>
        </div>
        <div v-for="(item, index) in transportModes" :key="index" class="transport-item">
          <select v-model="item.type" class="transport-select">
            <option value="car-gasoline">汽油车</option>
            <option value="car-diesel">柴油车</option>
            <option value="bus">公交车</option>
            <option value="train">火车</option>
          </select>
          <input 
            v-model.number="item.distance" 
            type="number" 
            placeholder="距离 (km)"
            min="0"
          >
          <button @click="removeTransport(index)" type="button" class="remove-btn">×</button>
        </div>
        <button @click="addTransport" type="button" class="add-btn">添加交通方式</button>
      </div>
      
      <div class="form-section">
        <h2>饮食消费</h2>
        <div class="input-group">
          <label for="meat">肉类消费 (kg)</label>
          <input 
            id="meat"
            v-model.number="food.meat" 
            type="number" 
            placeholder="例如: 2"
            step="0.1" 
            min="0"
          >
        </div>
        <div class="input-group">
          <label for="dairy">奶制品消费 (kg)</label>
          <input 
            id="dairy"
            v-model.number="food.dairy" 
            type="number" 
            placeholder="例如: 1"
            step="0.1" 
            min="0"
          >
        </div>
        <div class="input-group">
          <label for="vegetable">蔬菜消费 (kg)</label>
          <input 
            id="vegetable"
            v-model.number="food.vegetable" 
            type="number" 
            placeholder="例如: 3"
            step="0.1" 
            min="0"
          >
        </div>
      </div>
      
      <div v-if="error" class="error-message">
        {{ error }}
      </div>

      <button type="submit" :disabled="calculating || !isFormValid" class="submit-btn">
        <span v-if="calculating">计算中...</span>
        <span v-else>计算碳足迹</span>
      </button>
      
      <div v-if="result" class="result-display">
        <h2>计算结果</h2>
        <div class="result-total">
          总碳足迹: <span>{{ result.total.toFixed(2) }} kgCO₂</span>
        </div>
        <div class="result-breakdown">
          <p>⚡ 电力排放: <span>{{ result.energy.toFixed(2) }} kgCO₂</span></p>
          <p>🚗 交通排放: <span>{{ result.transport.toFixed(2) }} kgCO₂</span></p>
          <p>🥗 饮食排放: <span>{{ result.food.toFixed(2) }} kgCO₂</span></p>
        </div>
        <div class="result-tip">
          <p>💡 **环保小提示**: {{ getTip() }}</p>
        </div>
      </div>
    </form>
  </div>
</template>

<script>
import { mapActions } from 'vuex';

const EMISSION_FACTORS = {
  electricity: 0.85, 
  'car-gasoline': 0.12,
  'car-diesel': 0.14, 
  bus: 0.07,
  train: 0.03
};

const TIPS = [
  "减少待机功耗，及时关闭不用的电器。",
  "尽量选择公共交通工具出行。",
  "使用节能灯泡，如LED灯。",
  "短途出行可选择步行或骑自行车。",
  "合理使用空调，夏季调高1℃，冬季调低1℃。"
];

export default {
  name: 'CarbonCalculator',
  data() {
    return {
      energyUsage: null,
      transportModes: [],
      food: { meat: 0, dairy: 0, vegetable: 0 },
      result: null,
      calculating: false,
      error: ''
    }
  },
  computed: {
    isFormValid() {
      return this.energyUsage !== null && this.energyUsage >= 0;
    }
  },
  methods: {
    ...mapActions(['addCalculation']),
    addTransport() {
      this.transportModes.push({ type: 'car-gasoline', distance: 0 });
    },
    removeTransport(index) {
      this.transportModes.splice(index, 1);
    },
    async calculate() {
      if (!this.isFormValid) {
        this.error = '请输入有效的电力消耗值';
        return;
      }
      
      this.calculating = true;
      this.error = '';
      
      await new Promise(resolve => setTimeout(resolve, 500));
      
      const energyEmission = this.energyUsage * EMISSION_FACTORS.electricity;
      const transportEmission = this.transportModes.reduce((acc, curr) => {
        return acc + ((curr.distance || 0) * EMISSION_FACTORS[curr.type]);
      }, 0);
      const foodEmission = (this.food.meat || 0) * 5 + (this.food.dairy || 0) * 2 + (this.food.vegetable || 0) * 0.5;

      const newResult = {
        total: energyEmission + transportEmission + foodEmission,
        energy: energyEmission,
        transport: transportEmission,
        food: foodEmission
      };

      this.result = newResult;
      
      this.addCalculation(newResult);
      
      this.calculating = false;
    },
    getTip() {
      if (!this.result) return TIPS[0];
      const randomIndex = Math.floor(Math.random() * TIPS.length);
      return TIPS[randomIndex];
    }
  }
}
</script>

<style scoped>
.calculator-container {
  max-width: 800px;
  margin: 0 auto;
  padding: 40px 20px;
}

.calculator-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 30px;
  padding-bottom: 20px;
  border-bottom: 2px solid #f0f0f0;
}

.calculator-header h1 {
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

.calculator-form {
  background-size: 100% 100%;
  background-image: url('https://blog.visitacostadelsol.com/hs-fs/hubfs/b-1%20feb%2023-1.png?width=1800&height=1013&name=b-1%20feb%2023-1.png');
  background-position: center;
  background-repeat: no-repeat;
  background: rgba(255,255,255,0.7);
  backdrop-filter: blur(10px);
  padding: 30px;
  border-radius: 12px;
  box-shadow: none;
}

.form-section {
  margin-bottom: 30px;
}

.form-section h2 {
  font-size: 20px;
  color: #333;
  margin-bottom: 20px;
  border-left: 4px solid #4CAF50;
  padding-left: 10px;
}

.input-group {
  margin-bottom: 20px;
}

.input-group label {
  display: block;
  margin-bottom: 8px;
  font-weight: 500;
  color: #555;
}

input[type="number"], .transport-select {
  width: 100%;
  padding: 12px 16px;
  border: 2px solid #e1e5e9;
  border-radius: 8px;
  font-size: 16px;
  transition: all 0.3s;
  box-sizing: border-box;
}

input:focus, .transport-select:focus {
  outline: none;
  border-color: #4CAF50;
}

.transport-item {
  display: flex;
  gap: 10px;
  margin-bottom: 15px;
  align-items: center;
}

.transport-select {
  flex: 1;
}

.transport-item input {
  flex: 2;
}

.remove-btn {
  background: #f44336;
  color: white;
  border: none;
  border-radius: 50%;
  width: 32px;
  height: 32px;
  font-size: 20px;
  cursor: pointer;
  transition: background 0.3s;
  display: flex;
  align-items: center;
  justify-content: center;
  padding: 0;
}

.remove-btn:hover {
  background: #d32f2f;
}

.add-btn {
  background: #2196F3;
  color: white;
  border: none;
  padding: 10px 20px;
  border-radius: 6px;
  cursor: pointer;
  transition: background 0.3s;
}

.add-btn:hover {
  background: #1976D2;
}

.submit-btn {
  width: 100%;
  padding: 15px;
  background: #4CAF50;
  color: white;
  border: none;
  border-radius: 8px;
  font-size: 18px;
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

.error-message {
  background: #ffebee;
  color: #c62828;
  padding: 12px;
  border-radius: 6px;
  margin-bottom: 20px;
  font-size: 14px;
}

.result-display {
  margin-top: 30px;
  padding: 25px;
  background: #e8f5e9;
  border: 2px solid #c8e6c9;
  border-radius: 12px;
}

.result-display h2 {
  font-size: 20px;
  color: #2e7d32;
  margin-bottom: 20px;
  text-align: center;
}

.result-total {
  font-size: 24px;
  font-weight: bold;
  text-align: center;
  margin-bottom: 20px;
}

.result-total span {
  color: #4CAF50;
}

.result-breakdown p {
  font-size: 16px;
  margin: 10px 0;
  padding-left: 10px;
}

.result-breakdown span {
  font-weight: 500;
}

.result-tip {
  margin-top: 20px;
  padding: 15px;
  background: #fff9c4;
  border-radius: 8px;
  color: #5d4037;
}

.empty-transport {
  text-align: center;
  padding: 20px;
  color: #888;
  border: 2px dashed #ddd;
  border-radius: 8px;
  margin-bottom: 15px;
}
</style> 