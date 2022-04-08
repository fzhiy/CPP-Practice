/*** 
 * @Date: 2022-04-08 10:10:00
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-08 15:54:31
 */

// [编程题]找出出现次数最多的整数
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int main() {
    unordered_map<int, int> mp;
    int n;
    while (cin >> n) {
        mp[n] ++;
    }
    int maxCount = 0;
    for (auto it = mp.begin(); it != mp.end(); it ++) {
        maxCount = max(maxCount, it->second);
    }
    vector<int> temp;
    for (auto it = mp.begin(); it != mp.end(); it ++) {
        if (maxCount == it->second) {
            temp.push_back(it->first);
        }
    }
    sort(temp.begin(), temp.end(), greater<int>());
    cout << temp[0] << endl;
    return 0;
}

// [编程题]找第K大的整数
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, x;
    while (cin >> k) {
        priority_queue<int, vector<int>, greater<int> > pq;   // 最小堆
        set<int> st;
        while (cin >> x) {
            if (st.find(x) != st.end()) {
                continue;
            } else {
                st.insert(x);
                if (pq.size() >= k && x > pq.top()) {
                    pq.pop();
                } else if (pq.size() >= k && x < pq.top()) {    // 保证堆中只有k个元素，即最后的pq.top()即为所求
                    continue;
                }
                pq.push(x);
            }
        }
        cout << pq.top() << endl;
    }
    return 0;
}


// [编程题]删除vector中的重复元素
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    vector<int> nums;
    set<int> st;
    while (cin >> x) {
        if (st.count(x) != 0) continue;
        st.insert(x);
        nums.push_back(x);
    }
    // cout << nums.size() << endl;
    for (int num: nums) {
        cout << num << " ";
    }
    return 0;
}

// [编程题]LRU链表
#include <bits/stdc++.h>
using namespace std;
// list（底层数据结构是双向链表） 实现LRU（Least Recently Used最近最少使用）链表。
// set 保存最近最多使用的元素（最多为n个）， lru则是对应的链表元素
// O(m * n), m 表示输入元素x的个数， 这里取决于count(x)的复杂度为 O(n)，外面套了一层循环，所以时间复杂度是O(m * n)
int main() {
    int n;
    cin >> n;
    int x;
    list<int> lru;
    unordered_set<int> st;
    while (cin >> x) {
        if (st.count(x) == 1) {
            lru.remove(x);
            lru.push_back(x);
        } else {
            if (st.size() >= n) {
                st.erase(lru.front());
                lru.pop_front();
            }
            st.insert(x);
            lru.push_back(x);
        }
    }
    for (auto it = lru.rbegin(); it != lru.rend(); it ++) {
        cout << *it << " ";
    }
    return 0;
}

// [编程题]找出最大的3个整数
#include <bits/stdc++.h>
using namespace std;

// 最大的k个数，用最小堆 O(n * logk)
int main() {
    int x;
    priority_queue<int, vector<int>, greater<int> > pq;
    unordered_set<int> st;
    int k = 3;
    while (cin >> x) {
        if (st.count(x) == 1) continue;
        st.insert(x);
        if (pq.size() >= k) {
            if (x > pq.top()) {
                pq.pop();
                pq.push(x);
            }
        } else {
            pq.push(x);
        }
    }
    vector<int> res;
    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    return 0;
}

// [编程题]对struct进行排序
#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x;
    int y;
    bool operator < (const Point& rhs) {
        if (x != rhs.x) {
            return x < rhs.x;
        } else {
            return y < rhs.y;
        }
    }
};

int main() {
        int x = 0;
        int y = 0;
        std::vector<Point> vec;
        while (std::cin >> x >> y) {
                Point p;
                p.x = x;
                p.y = y;
                vec.push_back(p);
        }

        std::sort(vec.begin(), vec.end());

        for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
                std::cout << iter->x << " " << iter->y << std::endl;
        }

        return 0;
}

// [编程题]删除map中的指定元素
#include <iostream>
#include <map>
#include <string>

void remove_elements(std::map<std::string, int> &m) {
    for (auto it = m.begin(); it != m.end(); it ) {
        if (it->second == 10) {
            it = m.erase(it);
        } else {
            it ++;
        }
    }
}

int main() {
    std::map<std::string, int> m;
    std::string key;
    int val = 0;
    while (std::cin >> key >> val) {
        m[key] = val;
    }

    remove_elements(m);

    for (const auto &ele : m) {
        std::cout << ele.first << " " << ele.second << std::endl;
    }

    return 0;
}

// [编程题]根据IP查询城市
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct IPrange {
    ll low, high;
    string city;
    bool operator < (const IPrange& rhs) const {
        return low < rhs.low;
    }
};
int main() {
    int n;
    set<IPrange> st;
    while (cin >> n) {
        IPrange iprange;
        int a, b, c, d;
        for (int i = 0; i < n; i ++) {
            scanf("%d.%d.%d.%d", &a, &b, &c, &d);
            iprange.low = (a << 24) + (b << 16) + (c << 8) + d;
            scanf("%d.%d.%d.%d", &a, &b, &c, &d);
            iprange.high = (a << 24) + (b << 16) + (c << 8) + d;
            cin >> iprange.city;
            st.insert(iprange);
        }
        while (~scanf("%d.%d.%d.%d", &a, &b, &c, &d)) {
            ll query = (a << 24) + (b << 16) + (c << 8) + d;
            bool flag = false;
            for (auto it = st.begin(); it != st.end(); it ++) {
                if (it->low <= query && query <= it->high) {
                    flag = true;
                    cout << it->city << endl;
                    break;
                }
            }
            if (!flag) {
                cout << "none" << endl;
            }
        }
    }
    return 0;
}

// [编程题]实现一个动态调整大小的数组
// 用一个结构体模拟
// struct Array
// {
//     int capacity;
//     int used;
//     int* arr;
// };
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;
    vector<int> v;
    while (cin >> s) {
        if (s == "push") {
            cin >> n;
            v.push_back(n);
            cout << v.size() << endl;
        } else if (s == "pop") {
            cout << (!v.empty() ? v.back() : -1) << endl;
            if (!v.empty()) {
                v.pop_back();
            }
        } else if (s == "get") {
            cin >> n;
            if (n < 0 || n >= v.size()) {
                cout << -1 << endl;
            } else {
                cout << v[n] << endl;
            }
        }
    }
    return 0;
}

// [编程题]移动构造函数
#include <iostream>
#include <string>

class A {
public:
    A(const std::string& s) {
        _s = new std::string(s);
    }
    A() {} 
    // 重载赋值运算符
    void operator = (const std::string& s) {
        if (_s) delete _s;
        _s = new std::string(s);
    }
    // 析构函数
    // 移动构造函数
    A(std::string&& s) {
        if (_s) delete _s;
        _s = &s;
    }
    std::string s() const {
        return *_s;
    }
private:
    std::string *_s;
};

int main() {
    std::string input;
    std::cin >> input;
    A a(input);
    A b(std::move(a));
    std::cout << b.s() << std::endl;
    A c;
    c = std::move(b);
    std::cout << c.s() << std::endl;
    return 0;
}

// [编程题]检查给定字符串中的多种括号是否匹配
// 考 栈 （先进后出的性质）
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        stack<char> stk;
        int size = s.size();
        bool flag = true;
        for (char& ch: s) {
            if (ch == ')' || ch == ']' || ch == '}') {
                if (stk.empty()) {
                    flag = false;
                    break;
                } else {
                    char op = stk.top();
                    if (ch == ')' && op != '(' || ch == ']' && op != '[' || ch == '}' && op != '{') {
                        flag = false;
                        break;
                    } else {
                        stk.pop();
                    }
                }
            } else if (ch == '(' || ch == '[' || ch == '{'){
                stk.push(ch);
            }
        }
        cout << (flag ? "true" : "false") << endl;
    }
    return 0;
}

// [编程题]设计一个scope pointer
#include <iostream>

class ScopedPtr {
public:
    ScopedPtr(int* x) : _x(x) {
    }
    ScopedPtr() {}
    ~ScopedPtr() {delete _x;}
    // 解引用运算符 重载, 返回值必须是 引用，因为下面的 *ptr是左值
    int& operator * () {
        return *_x;
    }
    // *= 运算符重载
    int operator *= (int n) {
        return (*_x) * n;
    }
private:
    int* _x;
};

void test(int n) {
    ScopedPtr ptr(new int(n));

    *ptr *= 2;

    std::cout << *ptr << std::endl;
}

int main () {
    int n = 0;
    std::cin >> n;

    test(n);

    return 0;
}
