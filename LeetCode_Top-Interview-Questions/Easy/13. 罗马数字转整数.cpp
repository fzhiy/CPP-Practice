/*** 
 * @Date: 2022-04-12 14:38:20
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-12 14:51:52
 */

// 模拟
class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int num = 0;
        for (int i = 0; i < n; i ++) {
            if (s[i] == 'I') {
                if (i + 1 < n && s[i + 1] == 'V' || s[i + 1] == 'X') {
                    num += (s[i + 1] == 'V' ? 4 : 9);
                    i ++;
                } else {
                    num ++;
                }
            } else if (s[i] == 'X') {
                if (i + 1 < n && s[i + 1] == 'L' || s[i + 1] == 'C') {
                    num += (s[i + 1] == 'L' ? 40 : 90);
                    i ++;
                } else {
                    num += 10;
                }
            } else if (s[i] == 'C') {
                if (i + 1 < n && s[i + 1] == 'D' || s[i + 1] == 'M') {
                    num += (s[i + 1] == 'D' ? 400 : 900);
                    i ++;
                } else {
                    num += 100;
                }
            } else if (s[i] == 'V') {
                num += 5;
            } else if (s[i] == 'L') {
                num += 50;
            } else if (s[i] == 'D') {
                num += 500;
            } else if (s[i] == 'M') {
                num += 1000;
            }
        }
        return num;
    }
};