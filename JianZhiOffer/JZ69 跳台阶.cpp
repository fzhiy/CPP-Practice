/*** 
 * @Date: 2022-03-21 08:59:49
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-21 09:04:46
 */

// DP O(n) / O(n)
class Solution {
public:
    int jumpFloor(int number) {
        int n = number;
        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i ++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// 实际上只用到了dp[0] 和 dp[1]两个空间，所以可以做空间优化, O(n) / O(1)
class Solution {
public:
    int jumpFloor(int number) {
        int n = number;
        int prev = 1, cur = 1;
        for (int i = 2; i <= n; i ++) {
            int temp = prev + cur;
            prev = cur;
            cur = temp;
        }
        return cur;
    }
};