# Docker 手动部署指南

## 1. 准备工作

首先将项目文件复制到本地目录：
- app.py
- config.py
- utils.py
- init_db.py
- requirements.txt
- Dockerfile
- docker-compose.yml
- .env (请参考示例创建)

## 2. 创建环境变量文件 (.env)

创建一个名为`.env`的文件，包含以下内容：

```
DB_HOST=8.138.115.164
DB_PORT=3306
DB_USER=root
DB_PASSWORD=Xzk200411.
DB_NAME=login_user_management
SECRET_KEY=your_secret_key
DEBUG=False
```

## 3. 上传到服务器

使用SFTP工具（如FileZilla、WinSCP）将所有文件上传到服务器，例如上传到 `/root/carbon_calculator` 目录

## 4. 在服务器上安装Docker和Docker Compose

```bash
# 更新系统包
sudo apt-get update

# 安装必要的依赖
sudo apt-get install -y apt-transport-https ca-certificates curl software-properties-common

# 添加Docker官方GPG密钥
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

# 设置Docker存储库
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"

# 更新包索引
sudo apt-get update

# 安装Docker CE
sudo apt-get install -y docker-ce

# 安装Docker Compose
sudo curl -L "https://github.com/docker/compose/releases/download/v2.20.0/docker-compose-linux-x86_64" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose
```

## 5. 构建并启动Docker容器

```bash
cd /root/carbon_calculator

# 构建镜像
sudo docker-compose build --no-cache

# 启动容器
sudo docker-compose up -d
```

## 6. 验证部署

```bash
# 检查容器运行状态
sudo docker ps

# 查看日志
sudo docker logs flask_carbon_calculator
```

服务应该在 http://8.138.115.164:5000 上运行

## 7. 管理命令参考

```bash
# 停止服务
sudo docker-compose down

# 重启服务
sudo docker-compose restart

# 查看实时日志
sudo docker-compose logs -f

# 进入容器内部
sudo docker exec -it flask_carbon_calculator /bin/bash
``` 