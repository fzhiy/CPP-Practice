/*** 
 * @Date: 2022-05-02 22:09:39
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-05-02 22:18:37
 */

// DP，dp[0][i]: 表示对于nums[0,...,i]不偷第i个时的最高金额，
//     dp[1][i]: 表示对于nums[0,...,i] 偷第i个时的最高金额，
// O(n) / O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = 0, dp[1][0] = nums[0];
        for (int i = 1; i < n; i ++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = dp[0][i - 1] + nums[i];
        }
        return max(dp[0][n - 1], dp[1][n - 1]);
    }
};


// 优化
// O(n) / O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int cur0 = 0, cur1 = nums[0];
        for (int i = 1; i < n; i ++) {
            int temp = cur0;
            cur0 = max(cur0, cur1);
            cur1 = temp + nums[i];
        }
        return max(cur0, cur1);
    }
};