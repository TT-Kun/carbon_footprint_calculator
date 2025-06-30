# PowerShell部署脚本

# 设置变量
$SERVER_IP = "8.138.115.164"
$SERVER_USER = "root"  # 使用您的实际用户名
$APP_DIR = "/opt/carbon_calculator"
$SSH_KEY = ""  # 如果有SSH密钥，请指定路径

Write-Host "开始部署到服务器: $SERVER_IP..."

# 创建本地部署包
Write-Host "正在创建部署包..."
Compress-Archive -Path app.py, config.py, utils.py, init_db.py, requirements.txt, gunicorn_config.py, carbon_calculator.service -DestinationPath deployment.zip -Force

# 上传文件到服务器
Write-Host "正在上传文件到服务器..."
if ($SSH_KEY -ne "") {
    scp -i $SSH_KEY deployment.zip $SERVER_USER@$SERVER_IP`:~/
} else {
    scp deployment.zip $SERVER_USER@$SERVER_IP`:~/
}

# SSH连接执行远程命令
Write-Host "正在服务器上设置应用..."
if ($SSH_KEY -ne "") {
    ssh -i $SSH_KEY $SERVER_USER@$SERVER_IP "
        # 创建应用目录
        sudo mkdir -p $APP_DIR
        sudo unzip -o ~/deployment.zip -d $APP_DIR
        cd $APP_DIR
        
        # 设置Python环境
        sudo apt-get update
        sudo apt-get install -y python3-venv python3-dev unzip
        python3 -m venv venv
        source venv/bin/activate
        pip install --upgrade pip
        pip install -r requirements.txt
        
        # 初始化数据库
        python init_db.py
        
        # 设置systemd服务
        sudo cp carbon_calculator.service /etc/systemd/system/
        sudo systemctl daemon-reload
        sudo systemctl enable carbon_calculator
        sudo systemctl restart carbon_calculator
        
        # 检查服务状态
        systemctl status carbon_calculator
    "
} else {
    ssh $SERVER_USER@$SERVER_IP "
        # 创建应用目录
        sudo mkdir -p $APP_DIR
        sudo apt-get install -y unzip
        sudo unzip -o ~/deployment.zip -d $APP_DIR
        cd $APP_DIR
        
        # 设置Python环境
        sudo apt-get update
        sudo apt-get install -y python3-venv python3-dev
        python3 -m venv venv
        source venv/bin/activate
        pip install --upgrade pip
        pip install -r requirements.txt
        
        # 初始化数据库
        python init_db.py
        
        # 设置systemd服务
        sudo cp carbon_calculator.service /etc/systemd/system/
        sudo systemctl daemon-reload
        sudo systemctl enable carbon_calculator
        sudo systemctl restart carbon_calculator
        
        # 检查服务状态
        systemctl status carbon_calculator
    "
}

Write-Host "部署完成！" 