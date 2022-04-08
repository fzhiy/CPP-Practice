/*** 
 * @Date: 2022-04-08 10:10:00
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-08 11:18:54
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
