/*** 
 * @Date: 2022-03-20 11:54:22
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-20 11:55:45
 */

// 1）模拟，O(n*k) / O(1)；
// 2）单调减队列(deque)， O(n) / O(k)，k为窗口大小
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        if (num.size() < size || size < 1) return res;
        deque<int> dq;    // 单调队列 存储索引, 对应元素单调递减
        for (int i = 0; i < num.size(); i++) {
            while (!dq.empty() && num[dq.back()] < num[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() + size <= i) {    // 队列头部过期，即超出了当前窗口大小
                dq.pop_front();
            }
            if (i + 1 >= size) {
                // 形成了窗口
                res.push_back(num[dq.front()]);
            }
        }
        return res;
    }
};