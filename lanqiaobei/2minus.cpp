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

    // ���ļ�
    ofstream outfile("output.txt");
    if (!outfile) {
        cerr << "�޷����ļ���" << endl;
        return 1;
    }

    // �����д���ļ�
    for (auto x : v) {
        outfile << x << ",";
    }

    // �ر��ļ�
    outfile.close();

    cout << "�����д�뵽 output.txt �ļ��С�" << endl;
    return 0;
}
