import { createStore } from 'vuex';
import { register as apiRegister, login as apiLogin, getMe } from '@/api/user';

const loadState = () => {
  try {
    const serializedState = localStorage.getItem('carbonState');
    return serializedState ? JSON.parse(serializedState) : undefined;
  } catch (e) {
    return undefined;
  }
};

const saveState = (state) => {
  localStorage.setItem('carbonState', JSON.stringify(state));
};

const initialState = {
  user: null,
  users: [],
  calculations: [],
  currentEmission: null
};

const store = createStore({
  state: loadState() || initialState,
  mutations: {
    SET_USER(state, user) {
      state.user = user;
      if (user && !state.users.some(u => u.email === user.email)) {
        state.users.push(user);
      }
    },
    ADD_CALCULATION(state, calculation) {
      state.calculations.push({
        ...calculation,
        timestamp: new Date().toISOString()
      });
    },
    LOGOUT(state) {
      state.user = null;
      localStorage.removeItem('token');
    },
    CLEAR_CALCULATIONS(state) {
      state.calculations = [];
    }
  },
  actions: {
    async register({ commit }, user) {
      try {
        const res = await apiRegister(user);
        if (res.data.success) {
          localStorage.setItem('token', res.data.token);
          // 获取用户信息
          const me = await getMe();
          commit('SET_USER', me.data.user);
          saveState(this.state);
          return me.data.user;
        } else {
          throw new Error(res.data.message);
        }
      } catch (err) {
        throw new Error(err.response?.data?.message || err.message || '注册失败');
      }
    },
    async login({ commit }, credentials) {
      try {
        const res = await apiLogin(credentials);
        if (res.data.success) {
          localStorage.setItem('token', res.data.token);
          // 获取用户信息
          const me = await getMe();
          commit('SET_USER', me.data.user);
          saveState(this.state);
          return me.data.user;
        } else {
          throw new Error(res.data.message);
        }
      } catch (err) {
        throw new Error(err.response?.data?.message || err.message || '登录失败');
      }
    },
    logout({ commit }) {
      commit('LOGOUT');
      saveState(this.state);
    },
    addCalculation({ commit }, calculation) {
      commit('ADD_CALCULATION', calculation);
      saveState(this.state);
    }
  },
  getters: {
    isAuthenticated: state => !!state.user,
    weeklyData: state => {
      // 获取今天是周几（0-6，周日为0）
      const today = new Date();
      const dayOfWeek = (today.getDay() + 6) % 7; // 0=周一, 6=周日
      // 计算本周周一的日期
      const monday = new Date(today);
      monday.setDate(today.getDate() - dayOfWeek);
      monday.setHours(0,0,0,0);

      // 生成本周7天的日期对象
      const weekDays = Array.from({length: 7}, (_, i) => {
        const d = new Date(monday);
        d.setDate(monday.getDate() + i);
        return d;
      });

      // 初始化结果数组
      const result = Array(7).fill(0);

      // 遍历所有记录，归类到本周的正确位置
      state.calculations.forEach(calc => {
        if (!calc.timestamp) return;
        const calcDate = new Date(calc.timestamp);
        calcDate.setHours(0,0,0,0);
        for (let i = 0; i < 7; i++) {
          if (calcDate.getTime() === weekDays[i].getTime()) {
            result[i] += calc.total;
          }
        }
      });
      return result;
    },
    totalCalculations: state => state.calculations.length,
    averageEmission: state => {
      if (state.calculations.length === 0) return 0;
      const total = state.calculations.reduce((sum, calc) => sum + calc.total, 0);
      return total / state.calculations.length;
    }
  }
});

store.subscribe((mutation, state) => {
  saveState(state);
});

export default store;