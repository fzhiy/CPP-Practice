/*** 
 * @Date: 2022-04-13 20:44:21
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 20:45:36
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i ++) {
            swap(s[i], s[n - i - 1]);
        }
    }
};