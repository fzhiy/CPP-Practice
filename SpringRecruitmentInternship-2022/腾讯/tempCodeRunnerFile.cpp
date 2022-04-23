#include <bits/stdc++.h>
using namespace std;

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