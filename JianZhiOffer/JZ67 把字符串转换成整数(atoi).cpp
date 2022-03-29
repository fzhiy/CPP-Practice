/*** 
 * @Date: 2022-03-29 14:23:37
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-29 14:23:38
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return int整型
     */
    int StrToInt(string s) {
        // write code here
        int flag = 1, i = 0;
        int len = s.size();
        while (i < len && s[i] == ' ') i++;
        if (i < len) {
            if (s[i] == '-') {
                flag = -1;
                i ++;
            } else if (s[i] == '+') {
                i ++;
            }
        }
        long long num = 0;
        while (i < len) {
            if (s[i] < '0' || s[i] > '9') break;
            num = num * 10 + (s[i] - '0');
            if (flag == -1 && -1.0 * num < INT_MIN) {
                return INT_MIN;
            } else if (flag == 1 && num > INT_MAX) {
                return INT_MAX;
            }
            i ++;
        }
        if (flag == -1) {
            num = -num;
        }
        return (int)num;
    }
};