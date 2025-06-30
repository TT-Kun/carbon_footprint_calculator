<!-- <template>
  <div>
    <canvas id="barChart"></canvas>
  </div>
</template>

<script>
import { onMounted, ref } from 'vue';
import { Chart } from 'chart.js';

export default {
  props: ['data'],
  setup(props) {
    const barChartRef = ref(null);

    onMounted(() => {
      new Chart(barChartRef.value, {
        type: 'bar',
        data: {
          labels: ['周一', '周二', '周三', '周四', '周五', '周六', '周日'],
          datasets: [{
            label: '每日碳足迹 (kg CO₂)',
            data: props.data,
            backgroundColor: '#42A5F5',
            borderColor: '#1E88E5',
            borderWidth: 1
          }]
        }
      });
    });

    return {
      barChartRef
    };
  }
};
</script> -->
<template>
  <div class="chart-container">
    <canvas ref="chartCanvas"></canvas>
  </div>
</template>

<script>
import { Chart, registerables } from 'chart.js';
Chart.register(...registerables);

export default {
  props: {
    data: Array,
    labels: Array
  },
  data() {
    return {
      chartInstance: null
    }
  },
  watch: {
    data: {
      handler(newData) {
        if (this.chartInstance) {
          this.chartInstance.data.datasets[0].data = newData;
          this.chartInstance.update();
        }
      },
      deep: true
    }
  },
  mounted() {
    this.initChart();
  },
  beforeUnmount() {
    if (this.chartInstance) {
      this.chartInstance.destroy();
    }
  },
  methods: {
    initChart() {
      const ctx = this.$refs.chartCanvas.getContext('2d');
      
      this.chartInstance = new Chart(ctx, {
        type: 'bar',
        data: {
          labels: this.labels || ['周一', '周二', '周三', '周四', '周五', '周六', '周日'],
          datasets: [{
            label: '每日碳足迹 (kg CO₂)',
            data: this.data,
            backgroundColor: '#4CAF50',
            borderColor: '#388E3C',
            borderWidth: 1,
            borderRadius: 4
          }]
        },
        options: {
          responsive: true,
          maintainAspectRatio: false,
          scales: {
            y: {
              beginAtZero: true,
              title: {
                display: true,
                text: '千克二氧化碳'
              }
            },
            x: {
              grid: {
                display: false
              }
            }
          },
          plugins: {
            legend: {
              position: 'top'
            },
            tooltip: {
              backgroundColor: 'rgba(0,0,0,0.8)',
              bodyColor: '#fff',
              titleColor: '#fff'
            }
          }
        }
      });
    }
  }
}
</script>

<style scoped>
.chart-container {
  position: relative;
  height: 400px;
  margin: 20px 0;
}
</style>