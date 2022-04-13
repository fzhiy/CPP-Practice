/*** 
 * @Date: 2022-04-13 20:56:13
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 20:59:12
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26);
        if (s.size() != t.size()) return false; // 长度不同 特判
        for (char ch : s) {
            count[ch - 'a'] ++;
        }
        for (char ch : t) {
            if (count[ch - 'a'] == 0) {
                return false;
            }
            count[ch - 'a'] --;
        }
        return true;
    }
};