/*** 
 * @Date: 2022-04-27 15:57:15
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-27 16:30:13
 */

// O(n * m) / O(m), m 表示生成的字符串中的最大长度
class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        string cur;
        for (int i = 2; i <= n; i ++) {
            int start = 0, pos = 0;
            cur = "";
            while (pos < prev.size()) {
                while (pos < prev.size() && prev[pos] == prev[start]) {
                    pos ++;
                }
                cur += to_string(pos - start) + prev[start];
                start = pos;
            }
            prev = cur;
        }
        return prev;
    }
};