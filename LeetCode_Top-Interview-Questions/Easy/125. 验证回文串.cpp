/*** 
 * @Date: 2022-04-13 19:57:05
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 20:02:43
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
            if (s[j] >= 'A' && s[j] <= 'Z') s[j] += 32;
            if (!isalnum(s[i])) {   // 不是字母 或 数字
                i ++;
                continue;
            }
            if (!isalnum(s[j])) {
                j --;
                continue;
            }
            if (s[i] != s[j]) {
                return false;
            }
            i ++, j --;
        }
        return true;
    }
};