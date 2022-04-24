/*** 
 * @Date: 2022-04-24 09:31:36
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-24 18:50:04
 */

// [编程题]压缩算法
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return string字符串
     */
    string compress(string str) {
        // write code here
        stack<char> st;
        string res("");
        int n = str.size();
        for (int i = 0; i < n; i++) {
            if (str[i] == ']') {
                char ch = st.top();
                string temp;
                while (ch >= 'A' && ch <= 'Z') {    // 压缩的字符
                    temp = ch + temp;
                    st.pop();
                    ch = st.top();
                }
                if (!st.empty()) {
                    st.pop();   //删除 '|'
                }
                int num = 0, cnt = 1;
                ch = st.top();
                while (ch >= '0' && ch <= '9') {
                    num = num + (ch - '0') * cnt;
                    st.pop();
                    ch = st.top();
                    cnt *= 10;
                }
                string str_store;
                while (num --) {
                    str_store += temp;
                }
                if (!st.empty()) {  
                    st.pop();     // 删除'['
                }
                for (char ch : str_store) {
                    st.push(ch);
                }
            } else {
                st.push(str[i]);
            }
        }
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

int main() {
    string str = "HG[3|B[2|CA]]F";
    Solution sol;
    string res = sol.compress(str);
    cout << res << endl;
    return 0;
}

// [编程题]逛街
// 单调栈的应用
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param heights int整型vector 
     * @return int整型vector
     */
    vector<int> findBuilding(vector<int>& heights) {
        // write code here
        int n = heights.size();
        vector<int> nums(n, 1);
        stack<int> p;
        for (int i = 0; i < n; i ++) {
            nums[i] += p.size();
            while (!p.empty() && p.top() <= heights[i]) {   // 维护一个单调栈
                p.pop();
            }
            p.push(heights[i]);
        }
        stack<int> q;
        for (int i = n - 1; i >= 0; i --) {
            nums[i] += q.size();
            while (!q.empty() && q.top() <= heights[i]) {
                q.pop();
            }
            q.push(heights[i]);
        }
        return nums;
    }
};
int main() {
    int t;
    vector<int> heights = {5,3,8,3,2,5};
    Solution sol;
    vector<int>nums = sol.findBuilding(heights);
    for (auto num : nums) {
        cout << num << " ";
    }
    return 0;
}

// [编程题]逆序对
// 归并排序，求出逆序对 和 顺序对的个数，然后交换p范围的 顺逆序对数。 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void print(vector<ll> &nums) {
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}
void merge_sort(vector<int>& nums, vector<int>& copy, int low, int high, int idx, vector<ll>& order) {
    if (low >= high) return ;
    int mid = low + (high - low) / 2;
    int start1 = low, end1 = mid;
    int start2 = mid + 1, end2 = high;
    merge_sort(nums, copy, start1, end1, idx - 1, order);
    merge_sort(nums, copy, start2, end2, idx - 1, order);
    ll index = low, cnt = 0;
    while (start1 <= end1 && start2 <= end2) {
        if (nums[start1] > nums[start2]) {
            copy[index ++] = nums[start2 ++];
            cnt += (end1 - start1 + 1);     // 构成的逆序对
        } else {
            copy[index ++] = nums[start1 ++];
        }
    }
    while (start1 <= end1) {
        copy[index ++] = nums[start1 ++];
    }
    while (start2 <= end2) {
        copy[index ++] = nums[start2 ++];
    }
    for (index = low; index <= high; index ++) {
        nums[index] = copy[index];
    }
    order[idx] += cnt;
    // print(nums);
}

int main() {
    int n, m;
    while (cin >> n) {
        int p = 1 << n, q;
        vector<int> a(p);
        for (int i = 0; i < p; i ++) {
            cin >> a[i];
        }
        vector<ll> order(n + 1, 0);        // order[i]对应 分组大小为2^i 的顺序对的个数
        vector<ll> reOrder(n + 1, 0);       // reOrder[i] 对应分组大小为2^i 的逆序对的个数
        vector<int> b(a.rbegin(), a.rend());
        vector<int> copy(p, 0);
        merge_sort(a, copy, 0, p - 1, n, reOrder);
        copy.clear();
        merge_sort(b, copy, 0, p - 1, n, order);
        // cout << "排序后的结果: \n";
        // print(a);
        // print(b);
        // cout << "==============\n";
        // print(order);
        // print(reOrder);
        cin >> m;
        while (m --) {
            cin >> q;
            for (int i = 1; i <= q; i ++) {
                swap(order[i], reOrder[i]);
            }
            ll res = 0;
            for (int i = 1; i <= n; i ++) {
                res += reOrder[i];
            }
            cout << res << endl;
        }
    }
    return 0;
}


// [编程题]假期
#include <bits/stdc++.h>
using namespace std;
const int maxn = 0x3f3f3f3f;

int main() {
    int n;
    cin >> n;
    vector<int> company(n);
    vector<int> gym(n);
    for (int i = 0; i < n; i ++) {
        cin >> company[i];
    }
    for (int i = 0; i < n; i ++) {
        cin >> gym[i];
    }
    vector<vector<int> >dp(3, (vector<int> (n + 1, maxn)));
    // dp[0][i]: 表示第i天可以休息的情况下的 最少休息天数
    // dp[1][i]: 表示第i天可以工作的情况下的 最少休息天数
    // dp[2][i]: 表示第i天可以健身的情况下的 最少休息天数
    
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[2][0] = 0;
    for (int i = 1; i <= n; i ++) {
        dp[0][i] = 1 + min(dp[0][i - 1], min(dp[1][i - 1], dp[2][i - 1]));   // 第 i 天休息
        // 如果可以工作
        if (company[i - 1] == 1) {
            dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]);
        }
        // 如果可以健身
        if (gym[i - 1] == 1) {
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]);
        }
    }
    cout << min(dp[0][n], min(dp[1][n], dp[2][n])) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 0x3f3f3f3f;

// [编程题]视野争夺
// 贪心法 经典题
struct Node {
    int l, r;
    bool operator < (const Node& rhs) {
        if (l != rhs.l) {
            return l < rhs.l;
        } else {
            return r < rhs.r;
        }
    }
};

int main() {
    int n, L;
    cin >> n >> L;
    vector<Node> nodes(n);
    for (int i = 0; i < n; i ++) {
        cin >> nodes[i].l >> nodes[i].r;
    }
    sort(nodes.begin(), nodes.end());
    bool find = false;
    int end = 0, num = 0;
    int index = -1;
    while (end < L) {
        find = false;
        int tempEnd = end;
        // 每次找覆盖最远的点
        for (int i = index + 1; i < n; i ++) {
            if (end >= nodes[i].r) {
                continue;
            }
            if (end < nodes[i].l) { // 已经存在不能覆盖的区间
                break;
            }
            if (tempEnd < nodes[i].r) {
                tempEnd = nodes[i].r;
                find = true;
                index = i;
            }
        }
        if (!find) {
            break;
        } else {
            end = tempEnd;
            num ++;
        }
    }
    if (!find) {
        cout << -1 << endl;
    } else {
        cout << num << endl;
    }
    return 0;
}