#include<bits/stdc++.h>
using namespace std;

typedef struct Stu
{
    char num[7];
    string name;
    int grade;
}stu;

bool cmp1(stu a, stu b) {
    for (int i = 0; i < 6; i++) {
        if (a.num[i] - '0' > b.num[i] - '0')
            return false;
        else if (a.num[i] - '0' < b.num[i] - '0')
            return true;
    }
}

bool cmp2(stu a, stu b) {
    if (a.name == b.name) {
        return cmp1(a, b);
    }
    return a.name < b.name;
}

bool cmp3(stu a, stu b) {
    if (a.grade == b.grade) {
        return cmp1(a, b);
    }
    return a.grade <b.grade;
}

int main() {
    int n, type;
    cin >> n >> type;
    vector<stu> ware;
    for (int i = 0; i < n; i++) {
        stu temp;
        cin >> temp.num >> temp.name >> temp.grade; // 修改此处的输入语句
        ware.push_back(temp);
    }
    if (n >= 2) {
        switch (type) {
            case 1:
                sort(ware.begin(), ware.end(), cmp1);
                break;
            case 2:
                sort(ware.begin(), ware.end(), cmp2);
                break;
            case 3:
                sort(ware.begin(), ware.end(), cmp3);
                break;
            default:
                break;
        }
    }
    for (int i = 0; i < ware.size(); i++) {
        cout << ware[i].num << " " << ware[i].name << " " << ware[i].grade << endl;
    }
    return 0;
}
