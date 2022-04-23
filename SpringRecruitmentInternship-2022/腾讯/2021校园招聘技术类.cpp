/*** 
 * @Date: 2022-04-23 10:01:52
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-23 11:06:14
 */

// [编程题]朋友圈(后端开发卷)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
// O(nlogn) / o(n)
// 并查集模板题
class UnionFind {
public:
    UnionFind(int n) {
        count = n;
        parent = vector<int>(n + 1);
        rank = vector<int>(n + 1, 1);
        for (int i = 1; i <= n; i ++) {
            parent[i] = i;
        }
    }
    int findRoot(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void merge(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if (rootX == rootY) return ;
        count --;
        if (rank[rootX] > rank[rootY]) {
            rank[rootX] += rank[rootY];
            parent[rootY] = parent[rootX];
        } else {
            rank[rootY] += rank[rootX];
            parent[rootX] = parent[rootY];
        }
    }
    bool isConnected(int x, int y) {
        return findRoot(x) == findRoot(y);
    }

// private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

int main() {
    int t, n;
    cin >> t;
    while (t --) {
        cin >> n;
        UnionFind uf = UnionFind(N);
        int x, y;
        for (int i = 0; i < n; i ++) {
            cin >> x >> y;
            if (uf.isConnected(x ,y)) {
                continue;
            }
            // cout << "x :" << x << "  y:" << y;
            uf.merge(x, y);
        }
        int ans = 0;
        for (int i = 1; i <= N; i ++) {
            ans = max(ans, uf.rank[i]);
        }
        cout << ans << endl;
    }
    return 0;    
}

// [编程题]第K小子串(客户端开发卷)
#include <bits/stdc++.h>
using namespace std;

// Top K问题，大根堆 O(n^2) / O(n), n 是 字符串s的长度
int main() {
    string s;
    while (cin >> s) {
        int k;
        cin >> k;
        priority_queue<string> pq;  // 大根堆, 求 top k小 的问题
        int n = s.size();
        set<string> st;
        for (int i = 0; i < n; i ++) {
            for (int j = 1; j <= n - i; j ++) { // 枚举长度
                string temp = s.substr(i, j);
                if (st.size() < k && st.find(temp) == st.end()) {
                    st.insert(temp);
                    pq.push(temp);
                } else if (st.find(temp) != st.end()) {
                    continue;
                } else if (st.size() >= k) {
                    string t = pq.top();
                    if (temp < t) {
                        pq.pop();
                        pq.push(temp);
                        st.erase(t);
                        st.insert(temp);
                    }
                }
            }
        }
        cout << pq.top() << endl;
    }
    return 0;
}

// [编程题]封闭图形的面积(技术研究卷)
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

// [编程题]队列操作(后端开发卷)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t --) {
        cin >> n;
        queue<int> q;
        while (n --) {
            string s;
            cin >> s;
            // getchar();
            int x;
            if (s == "PUSH") {
                cin >> x;
                q.push(x);
            } else if (s == "TOP") {
                if (q.empty()) {
                    cout << -1 << endl;
                } else {
                    cout << q.front() << endl;
                }
            } else if (s == "POP") {
                if (q.empty()) {
                    cout << -1 << endl;
                } else {
                    q.pop();
                }
            } else if (s == "SIZE") {
                cout << q.size() << endl;
            } else if (s == "CLEAR") {
                while (!q.empty()) {
                    q.pop();
                }
            }
        }
    }

    return 0;
}

