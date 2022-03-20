/*** 
 * @Date: 2022-03-20 14:34:26
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-20 14:38:09
 */
// O(n) / O(n), dp[i]表示以array[i-1]结束的元素的连续子数组的最大和
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        vector<int> dp(n+1, 0);
        int res = array[0];
        for (int i=1; i<=n; i++) {
            dp[i] = max(array[i-1], array[i-1] + dp[i-1]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

// O(n) / O(1)
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
//         vector<int> dp(n+1, 0);
        int res = array[0];
        int temp = 0;
        for (int i=1; i<=n; i++) {
            if (temp + array[i-1] < 0) {
                temp = 0;
            } else {
                temp += array[i-1];
            }
            res = max(res, temp);
        }
        if (res != 0) return res;
        return *max_element(array.begin(), array.end());    // 数组元素可能都是负数
    }
};