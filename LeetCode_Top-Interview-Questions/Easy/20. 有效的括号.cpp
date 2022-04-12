/*** 
 * @Date: 2022-04-12 15:08:00
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-12 15:14:53
 */

// 栈 O(n) / O(1)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if (stk.empty()) {
                    return false;
                }
                char ch = stk.top();
                if (s[i] == ')' && ch == '(' || s[i] == ']' && ch == '[' || s[i] == '}' && ch == '{') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};