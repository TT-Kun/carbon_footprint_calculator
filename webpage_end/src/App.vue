<!--
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-05-10 12:03:06
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-06-24 10:50:56
 * @FilePath: \tanzujiqianduan\src\App.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div id="app">
    <router-view></router-view>  <!-- 用来渲染当前路由的组件 -->
  </div>
</template>

<script>
export default {
  name: 'App',
};
</script>

<style>
body {
  min-height: 100vh;
  background-image: url('@/assets/bg.jpg');
  background-size: cover;
  background-position: center;
  background-repeat: no-repeat;
  background-attachment: fixed;
}

#app {
  /* 恢复内容区原有布局 */
  max-width: 1200px;
  margin: 0 auto;
  padding: 20px;
  min-height: 100vh;
  box-sizing: border-box;
}

nav {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(180px, 1fr));
  gap: 1rem;
  padding: 1.5rem;
  background: #f8f9fa;
  border-radius: 8px;
  margin: 20px 0;
}

nav a {
  padding: 12px;
  text-align: center;
  background: #4CAF50;
  color: white;
  border-radius: 5px;
  text-decoration: none;
  transition: all 0.3s;
}

nav a:hover {
  background: #388E3C;
  transform: translateY(-2px);
}

.form-container {
  max-width: 500px;
  margin: 30px auto;
  padding: 25px;
  background: white;
  border-radius: 10px;
  box-shadow: 0 2px 12px rgba(0,0,0,0.1);
}

input[type="number"],
input[type="email"],
input[type="password"],
select {
  width: 100%;
  padding: 10px;
  margin: 8px 0;
  border: 1px solid #ddd;
  border-radius: 4px;
  box-sizing: border-box;
}

button {
  background: #2196F3;
  color: white;
  border: none;
  padding: 12px 24px;
  border-radius: 5px;
  cursor: pointer;
  transition: background 0.3s;
}

button:hover {
  background: #1976D2;
}

.cta-section {
  text-align: center;
  color: #333;
  padding: 40px;
  border-radius: 16px;
  background: transparent !important;
  border: none !important;
  box-shadow: none !important;
}
</style>
