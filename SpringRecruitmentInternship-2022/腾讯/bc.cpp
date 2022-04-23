/*** 
 * @Date: 2022-04-23 10:20:39
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-23 11:06:09
 */
#include <bits/stdc++.h>
using namespace std;

// A^2 - 2 * A * B * C > 0才有解，求积分
// 否则无解。
double a, b, c;
double func(double y) {
    return y * y / (2 * b) - c / b * y - y * y * y / (6 * a);
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> a >> b >> c;
        double d = a * a - 2 * a * b * c;
        if (d < 0) {
            cout << 0 << endl;
        } else {
            double y1 = (a - sqrt(d)) / b;
            double y2 = (a + sqrt(d)) / b;
            cout << func(y2) - func(y1) << endl;
        }
    }
    return 0;
}