/*** 
 * @Date: 2022-03-21 11:04:55
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-21 11:04:55
 */

// O(n) / O(n)
class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
        if (nums.size() == 0 || nums[0] == '0') return 0;
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (nums[i-1] == '0') {
                if (nums[i-2] == '1' || nums[i-2] == '2') {
                    dp[i] = dp[i-2];
                } else {
                    return 0;
                }
            } else if (nums[i-1] >= '1' && nums[i-1] <= '6') {
                if (nums[i-2] == '1' || nums[i-2] == '2') {
                    dp[i] = dp[i-1] + dp[i-2];
                } else {
                    dp[i] = dp[i-1];
                }
            } else {
                if (nums[i-2] == '1') {
                    dp[i] = dp[i-1] + dp[i-2];
                } else {
                    dp[i] = dp[i-1];
                }
            }
        }
        return dp[n];
    }
};