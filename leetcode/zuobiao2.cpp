#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin.tie(0);
    cin >> m >> n;

    double x[100005], y[100005]; // 使用数组代替vector
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }

    vector<double> ax, ay;
    for (int i = 0; i < n; i++) {
        double j, k, a, b;
        cin >> j >> k >> a >> b;
        double temp_a = a, temp_b = b; // 提前声明临时变量
        for (int t = j; t <= k; t++) {
            if (x[t - 1] == 1) {
                a *= y[t - 1];
                b *= y[t - 1];
            } else if (x[t - 1] == 2) {
                double temp_a_new = temp_a * cos(y[t - 1]) - temp_b * sin(y[t - 1]);
                double temp_b_new = temp_a * sin(y[t - 1]) + temp_b * cos(y[t - 1]);
                temp_a = temp_a_new;
                temp_b = temp_b_new;
            }
        }
        ax.push_back(temp_a); // 将计算结果直接放入vector中
        ay.push_back(temp_b);
    }
    
    cout << fixed << setprecision(6);
    
    for (int i = 0; i < n; i++) {
        cout << ax[i] << " " << ay[i] << endl;
    }
    return 0;
}
