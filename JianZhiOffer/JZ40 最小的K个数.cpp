/*** 
 * @Date: 2022-03-26 11:20:27
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-26 11:38:01
 */

class Solution {
public:
    // 最大堆求最小的k个数。O(nlogk) / O(k), 调整堆的复杂度是O(logk)。
    // 特别适合处理海量数据 （不需要修改输入数组）
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int> pq; // C++优先队列默认是最大堆
        vector<int> res;
        if (input.empty() || !k) return res;
        pq.push(input[0]);
        for (int i = 1; i < input.size(); i ++) {
            if (pq.size() < k) {
                pq.push(input[i]);
            } else if (input[i] < pq.top()) {
                pq.pop();
                pq.push(input[i]);
            }
        }
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

// 基于partition（类似快排）的方法
// 对数组[l, r]一次快排partition过程可得到，[l, p), p, [p+1, r)三个区间,[l,p)为小于等于p的值
// [p+1,r)为大于等于p的值。
// 然后再判断p，利用二分法
// 1.  如果[l,p), p，也就是p+1个元素（因为下标从0开始），如果p+1 == k, 找到答案
// 2.  如果p+1 < k, 说明答案在[p+1, r)区间内，
// 3.  如果p+1 > k , 说明答案在[l, p)内
// O(n), 最坏情况下为O(n^2)；
// O(1)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        // priority_queue<int> pq; // C++优先队列默认是最大堆
        vector<int> res;
        if (input.empty() || !k) return res;
        int left = 0, right = input.size();
        while (left < right) {
            int p = partition(input, left, right);
            if (p + 1 == k) {
                return vector<int>({input.begin(), input.begin() + k});
            }
            if (p + 1 < k) {
                left = p + 1;
            } else {
                right = p;
            }
        }
        return res;
    }
    int partition(vector<int>& input, int left, int right) {
        int pivot = input[right - 1];
        int i = left;
        for (int j = left; j < right - 1; j ++) {
            if (input[j] < pivot) {
                swap(input[i ++], input[j]);
            }
        }
        swap(input[i], input[right - 1]);
        return i;
    }
};