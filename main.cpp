#include <iostream>
#include "Net.h"
#include "Utils.h"

using std::cout;
using std::endl;

int main() {

    // 创建网络
    Net net;

    // 读取训练数据
    const vector<Sample> trainDataSet = Utils::getTrainData("traindata.txt");

    // 训练网络
    net.train(trainDataSet);

    // 利用网络预测
    const vector<Sample> testDataSet = Utils::getTestData("testdata.txt");
    for (const Sample &testSample: testDataSet) {
        vector<double> pred = net.predict(testSample.in);
        cout << testSample.in[0] << " " << testSample.in[1] << " " << pred[0] << endl;
    }

    return 0;
}
