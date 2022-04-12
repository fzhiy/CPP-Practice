/*** 
 * @Date: 2022-04-12 14:53:47
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-12 15:06:46
 */
class Solution {
public:
    // 纵向比较，比较每个字符串的前缀，不同就返回结束循环
    // O(m * n), m 是 vector的长度，n是strs[0]的长度, O(1)
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs[0].size();
        int n = strs.size();
        for (int i = 0; i < len; i ++) {
            char ch = strs[0][i];
            for (int j = 1; j < n; j ++) {
                if (i == strs[j].size() || strs[j][i] != ch) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};