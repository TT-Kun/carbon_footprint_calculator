import { createRouter, createWebHistory } from 'vue-router';
import store from '../store';
import HomePage from '../views/HomePage.vue';
import Login from '../views/LoginPage.vue';
import Register from '../views/RegisterPage.vue';
import CarbonCalculator from '../views/CarbonCalculator.vue';
import UserInfo from '../views/UserInfo.vue';
import DailyRecord from '../views/DailyRecord.vue';

const routes = [
  { path: '/', component: HomePage },
  { path: '/login', component: Login },
  { path: '/register', component: Register },
  { path: '/calculator', component: CarbonCalculator, meta: { requiresAuth: true } },
  { path: '/user-info', component: UserInfo, meta: { requiresAuth: true } },
  { path: '/daily-record', component: DailyRecord, meta: { requiresAuth: true } }
];

const router = createRouter({
  history: createWebHistory(),
  routes
});

// 路由守卫
router.beforeEach((to, from, next) => {
  const isAuthenticated = store.getters.isAuthenticated;
  const requiresAuth = to.matched.some(record => record.meta.requiresAuth);

  if (requiresAuth && !isAuthenticated) {
    next('/login');
  } else if ((to.path === '/login' || to.path === '/register') && isAuthenticated) {
    next('/');
  } else {
    next();
  }
});

export default router;
