import multiprocessing

# 绑定的IP和端口
bind = "0.0.0.0:5000"

# 工作进程数量
workers = multiprocessing.cpu_count() * 2 + 1

# 工作模式
worker_class = 'gevent'

# 超时时间
timeout = 30

# 日志配置
loglevel = 'info'
accesslog = 'access.log'
errorlog = 'error.log'

# 守护进程运行
daemon = True 