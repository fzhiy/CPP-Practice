/*** 
 * @Date: 2022-03-21 10:10:58
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-21 10:10:58
 */

// O(n * m) / O(n * m)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        // write code here
        int n = str.size(), m = pattern.size();
        // 技巧：往原字符头部插入空格，这样得到 char 数组是从 1 开始，而且可以使得 dp[0][0] = true，可以将 true 这个结果滚动下去
        str = " " + str;
        pattern = " " + pattern;
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j ++) {
                // 如果下一个字符是'*', 则代表当前字符不能被单独使用，跳过
                if (j + 1 <= m && pattern[j + 1] == '*') continue;
                // 对应了 pattern[j] 为普通字符和 '.' 两种情况
                if (i - 1 >= 0 && pattern[j] != '*') {
                    dp[i][j] = dp[i-1][j-1] && (str[i] == pattern[j] || pattern[j] == '.');
                }
                // 对应了 pattern[j] 为 '*'的情况
                else if (pattern[j] == '*') {
                    dp[i][j] = (j >= 2 && dp[i][j - 2]) || (i >= 1 && dp[i - 1][j] && (str[i] == pattern[j-1] || pattern[j - 1] == '.'));
                }
            }
        }
        return dp[n][m];
    }
};