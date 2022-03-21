/*** 
 * @Date: 2022-03-21 10:21:00
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-21 10:23:40
 */

// O(n) / O(n * 2)
class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        if (prices.size() == 0) return 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        // dp[i][0] 表示以prices[i] 结尾时不持股的最大收益, 
        // dp[i][1] 表示以prices[i] 结尾时持股的最大收益
        dp[0][1] = -prices[0];
        dp[0][0] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][1] = max(-prices[i], dp[i - 1][1]);
            dp[i][0] = max(dp[i-1][1] + prices[i], dp[i - 1][0]);
        }
        return dp[n - 1][0];
    }
};

// O(n) / O(1)
class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        if (prices.size() == 0) return 0;
        int n = prices.size();
        int minPrice = prices[0], res = 0;
        for (int i = 1; i < n; i ++) {
            res = max(res, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return res;
    }
};
