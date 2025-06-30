# PowerShell Docker部署脚本

# 设置变量
$SERVER_IP = "8.138.115.164"
$SERVER_USER = "root"
$SSH_KEY = ""  # 如果有SSH密钥，请指定路径

Write-Host "开始Docker部署到服务器: $SERVER_IP..."

# 创建.env文件
Write-Host "创建环境变量文件..."
@"
DB_HOST=8.138.115.164
DB_PORT=3306
DB_USER=root
DB_PASSWORD=Xzk200411.
DB_NAME=login_user_management
SECRET_KEY=your_secret_key
DEBUG=False
"@ | Out-File -FilePath .env -Encoding utf8 -NoNewline

# 创建本地部署包
Write-Host "正在创建部署包..."
Compress-Archive -Path app.py, config.py, utils.py, init_db.py, requirements.txt, Dockerfile, docker-compose.yml, .env -DestinationPath docker_deployment.zip -Force

# 上传文件到服务器
Write-Host "正在上传文件到服务器..."
if ($SSH_KEY -ne "") {
    scp -i $SSH_KEY docker_deployment.zip $SERVER_USER@$SERVER_IP`:~/
} else {
    scp docker_deployment.zip $SERVER_USER@$SERVER_IP`:~/
}

# SSH连接执行远程命令
Write-Host "正在服务器上设置Docker容器..."
if ($SSH_KEY -ne "") {
    ssh -i $SSH_KEY $SERVER_USER@$SERVER_IP "
        # 安装Docker（如果尚未安装）
        if ! command -v docker &> /dev/null; then
            sudo apt-get update
            sudo apt-get install -y apt-transport-https ca-certificates curl software-properties-common
            curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
            sudo add-apt-repository 'deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable'
            sudo apt-get update
            sudo apt-get install -y docker-ce
        fi
        
        # 安装Docker Compose（如果尚未安装）
        if ! command -v docker-compose &> /dev/null; then
            sudo curl -L 'https://github.com/docker/compose/releases/download/v2.20.0/docker-compose-linux-x86_64' -o /usr/local/bin/docker-compose
            sudo chmod +x /usr/local/bin/docker-compose
        fi
        
        # 创建应用目录
        mkdir -p ~/carbon_calculator
        unzip -o ~/docker_deployment.zip -d ~/carbon_calculator
        cd ~/carbon_calculator
        
        # 启动Docker容器
        sudo docker-compose down
        sudo docker-compose build --no-cache
        sudo docker-compose up -d
        
        # 检查容器状态
        sudo docker ps
    "
} else {
    ssh $SERVER_USER@$SERVER_IP "
        # 安装Docker（如果尚未安装）
        if ! command -v docker &> /dev/null; then
            sudo apt-get update
            sudo apt-get install -y apt-transport-https ca-certificates curl software-properties-common
            curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
            sudo add-apt-repository 'deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable'
            sudo apt-get update
            sudo apt-get install -y docker-ce
        fi
        
        # 安装Docker Compose（如果尚未安装）
        if ! command -v docker-compose &> /dev/null; then
            sudo curl -L 'https://github.com/docker/compose/releases/download/v2.20.0/docker-compose-linux-x86_64' -o /usr/local/bin/docker-compose
            sudo chmod +x /usr/local/bin/docker-compose
        fi
        
        # 安装unzip（如果需要）
        sudo apt-get install -y unzip
        
        # 创建应用目录
        mkdir -p ~/carbon_calculator
        unzip -o ~/docker_deployment.zip -d ~/carbon_calculator
        cd ~/carbon_calculator
        
        # 启动Docker容器
        sudo docker-compose down
        sudo docker-compose build --no-cache
        sudo docker-compose up -d
        
        # 检查容器状态
        sudo docker ps
    "
}

Write-Host "Docker部署完成！服务运行在 http://$SERVER_IP:5000" 