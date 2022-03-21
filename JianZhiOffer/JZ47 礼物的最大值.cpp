/*** 
 * @Date: 2022-03-21 10:38:32
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-21 10:43:25
 */

// O(m * n) / O(m * n)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int maxValue(vector<vector<int> >& grid) {
        // write code here
        if (grid.size() < 1) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[1][1] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]) + grid[i][j];
            }
        }
        return dp[m][n];
    }
};

// O(m * n) / O(n * 2); 从上面的状态转移公式可以看出只同时用到了2行空间，所以可以用滚动数组优化
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int maxValue(vector<vector<int> >& grid) {
        // write code here
        if (grid.size() < 1) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        dp[0][1] = grid[0][0];
        bool flag = true;
        for (int i = 0; i < m; i++) {
            flag = !flag;
            for (int j = 0; j < n; j++) {
                dp[flag][j+1] = max(dp[!flag][j+1], dp[flag][j]) + grid[i][j];
            }
        }
        return max(dp[0][n], dp[1][n]);
    }
};