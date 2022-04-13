/*** 
 * @Date: 2022-04-13 19:44:42
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 19:44:42
 */
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (char ch : columnTitle) {
            res = res * 26 + (ch - 'A' + 1);
        }
        return res;
    }
};