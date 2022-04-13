/*** 
 * @Date: 2022-04-13 20:33:46
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 20:33:46
 */

// O(n) / O(sum), sum 为 字符串中字母的种类数量
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26, 0);
        for (auto& ch : s) {
            count[ch - 'a'] ++;
        }
        for (int i = 0; i < s.size(); i ++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};