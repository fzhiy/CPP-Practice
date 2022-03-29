/*** 
 * @Date: 2022-03-29 14:30:58
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-29 14:46:10
 */

class Solution {
public:
    // 插入排序的思想。插入 O(nlogn), 获取中位数O(1)
    void Insert(int num) {
        if (v.empty()) {
            v.push_back(num);
        } else {
            auto it = lower_bound(v.begin(), v.end(), num);
            v.insert(it, num);
        }
    }

    double GetMedian() { 
        int size = v.size();
        if (size & 1) {
            return v[size / 2];
        } else {
            return 1.0 * (v[size / 2] + v[size / 2 - 1]) / 2;
        }
    }
private:
    vector<int> v;
};


class Solution {
public:
    // 最大堆保存[0, medium]（按大小排序）对应的元素， 最小堆保存[medium+1, ..., n]（按大小排序）对应位置的元素
    // 插入时间复杂度O(logn), 获取中位数复杂度O(1), 空间复杂度O(n)
    void Insert(int num) {
        max_pq.push(num);
        min_pq.push(max_pq.top());
        max_pq.pop();
        if (max_pq.size() < min_pq.size()) {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }

    double GetMedian() { 
        if (max_pq.size() > min_pq.size()) {
            return max_pq.top();
        } else { // 两个堆的大小相等
            return (min_pq.top() + max_pq.top()) / 2.0;
        }
    }
private:
    priority_queue<int> max_pq;    // 最大堆
    priority_queue<int, vector<int>, greater<int>> min_pq;  // 最小堆
};