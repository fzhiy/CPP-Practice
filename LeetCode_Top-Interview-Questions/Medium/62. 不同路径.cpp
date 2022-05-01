/*** 
 * @Date: 2022-05-01 16:36:51
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-05-01 16:42:06
 */

// DP 或 组合数
// O(m * n) / O(m * n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i ++) {
            dp[i][1] = 1;
        }
        for (int j = 1; j <= n; j ++) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= m; i ++) {
            for (int j = 2; j <= n; j ++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

// 组合数 O(m) / O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res = 1;
        for (int x = n, y = 1; y < m; x++, y++) {
            res = res * x / y;
        }
        return res;
    }
};