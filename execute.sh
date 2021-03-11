node/linux-x64/Neuralium &
sleep 5
cd cli/linux-x64
./neuraliumcli LoadWallet $1
./neuraliumcli StartMining
./dog
