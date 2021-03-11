1. 安装

cd neuralium
sh install.sh

2. 使用
#	后台运行
screen sh execute.sh
LoadWallet
输入密码
StartMining
提示mining is enabled
exit
CTRL+A+D切换到前台
#	显示后台运行的进程
screen -ls
#	切换到后台的某个进程
screen -r {进程id}
#	查询钱包code
sh queryCode.sh
#	查询余额
sh queryIUM.sh {钱包code}
#	转账
sh sendIUM.sh {钱包id} {发送金额} {油费} {备注}
3. 常见问题

screen未安装
sudo apt install screen

unzip未安装
sudo apt install unzip

需要更新版本就把原neuraliums删了

然后重新进行安装流程
