mkdir node cli
mv neuralium.node* node
mv neuralium.cli* cli

cd node
tar -zxvf *
cd ..
cd cli
tar -zxvf *
cd ..

mv dog cli/linux-x64
