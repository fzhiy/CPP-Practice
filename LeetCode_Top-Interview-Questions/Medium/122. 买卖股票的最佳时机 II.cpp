
// 找 x 个有利润的区间
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        for (int i = 1; i < n; i ++) {
            if (prices[i] > prices[i - 1]) {        // 有利润
                res += (prices[i] - prices[i - 1]); 
            }
        }
        return res;
    }
};

// DP， O(n) / O(1)
// dp[0][i]: 表示 不买入prices[i] 的最大利润
// dp[1][i]: 表示 买入prices[i] 的最大利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        for (int i = 1; i < n; i ++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]);
        }
        return dp[0][n - 1];
    }
};

// O(n) / O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        int curNot = 0, curBuy = -prices[0];
        for (int i = 1; i < n; i ++) {
            int tempNot = max(curNot, curBuy + prices[i]);
            int tempBuy = max(curBuy, curNot - prices[i]);
            curNot = tempNot;
            curBuy = tempBuy;
        }
        return curNot;
    }
};