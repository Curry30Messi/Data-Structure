#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> t={};
    set<int> v;
    for (int i = 0; i < 34000; i++) {
        for (int j = 0; j <= i; j++) {
            int temp = i * i - j * j;
            v.insert(temp);
        }
    }

    // 打开文件
    ofstream outfile("output.txt");
    if (!outfile) {
        cerr << "无法打开文件！" << endl;
        return 1;
    }

    // 将结果写入文件
    for (auto x : v) {
        outfile << x << ",";
    }

    // 关闭文件
    outfile.close();

    cout << "结果已写入到 output.txt 文件中。" << endl;
    return 0;
}
