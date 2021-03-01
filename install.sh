mkdir node cli
mv neuralium.node* node
mv neuralium.cli* cli

cd node
tar -zxvf *
cd ..
cd cli
tar -zxvf *
cd ..

g++ main.cpp
mv a.out dog
mv dog cli/linux-x64
