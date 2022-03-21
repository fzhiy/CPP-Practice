/*** 
 * @Date: 2022-03-21 09:12:48
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-21 09:15:14
 */

// O(n^2) / (n)。 
// dp[n] = dp[n-1] + dp[n-2] + ... + dp[1];
// dp[n-1] = dp[n-2] + dp[n-3] + ... + dp[1];
// ==>> dp[n] = dp[n-1] * 2;
class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> dp(number + 1, 0);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= number; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j];
            }
        }
        return dp[number];
    }
};

// O(n) / O(1)
class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0) return 1;
        return 1 << (number - 1);
    }
};