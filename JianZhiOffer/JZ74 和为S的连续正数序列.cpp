/*** 
 * @Date: 2022-03-27 12:54:25
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-27 13:00:49
 */

// 方法1： 三重循环，枚举起点和终点，然后枚举并计算区间内的数的累加和 O(n^3)
// 方法2： 前缀和，二重循环。 O(n^2) / O(1)
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        int temp = 0;
        for (int i = 1; i <= sum / 2; i ++) {
            for (int j = i; j < sum; j ++) {
                temp += j;    // 前缀和思想
                if (sum == temp) {
                    vector<int> ans;
                    for (int k = i; k <= j; k ++) {
                        ans.push_back(k);
                    }
                    res.push_back(ans);
                } else if (sum < temp) {
                    temp = 0;
                    break;
                }
            }
        }
        return res;
    }
};

// 方法3；滑动窗口 O(n) / O(1)
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        int left = 1, right = 1;
        int temp = 0;
        while (left <= sum / 2) {
            if (temp < sum) {
                temp += right;
                right++;
            } else {
                if (temp == sum) {
                    vector<int> ans;
                    for (int i = left; i < right; i++) {
                        ans.push_back(i);
                    }
                    res.push_back(ans);
                }
                temp -= left;
                left ++;
            }
        }
        return res;
    }
};