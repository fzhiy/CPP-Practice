/*** 
 * @Date: 2022-04-11 15:12:42
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-11 15:47:41
 */

// [编程题]A+B(1)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << a + b << endl;
    }
    return 0;
}

// [编程题]A+B(2)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}

// [编程题]A+B(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int a, b;
    while (cin >> a >> b && a && b) {
        cout << a + b << endl;
    }
    return 0;
}

// [编程题]A+B(4)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int a, b;
    while (cin >> t && t) {
        int sum = 0;
        while (t--) {
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
    }
    return 0;
}

// [编程题]A+B(5)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int a, b;
    cin >> t;
    while (t--) {
        int n, sum = 0;
        cin >> n;
        while (n --) {
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
    }
    return 0;
}

// [编程题]A+B(6)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int a, b;
    while (cin >> t) {
        int sum = 0;
        while (t --) {
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
    }
    return 0;
}

// [编程题]A+B(7)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int a, b;
    int sum = 0;
    while (cin >> a) {
        sum += a;
        if (getchar() == '\n') {
            cout << sum << endl;
            sum = 0;
        }
    }
    return 0;
}

// [编程题]字符串排序(1)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int a, b;
    int sum = 0;
    cin >> t;
    vector<string> v(t);
    for (int i = 0; i < t; i ++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (auto s: v) {
        cout << s << " ";
    }
    return 0;
}

// [编程题]字符串排序(2)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int a, b;
    string s;
    vector<string> v;
    while (cin >> s) {
        v.push_back(s);
        if (getchar() == '\n') {
            sort(v.begin(), v.end());
            for (auto s: v) {
                cout << s << " ";
            }
            cout << endl;
            v.clear();
        }
    }
    return 0;
}

// [编程题]字符串排序(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str, line;
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<string> v;
        while (getline(ss, str, ',')) {
            v.emplace_back(str);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; i ++) {
            cout << v[i] << ",";
        }
        cout << v.back() << endl;
    }
    return 0;
}

// [编程题]自测本地通过提交为0
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    while (cin >> a >> b) {
        cout << a + b << endl;
    }
    return 0;
}