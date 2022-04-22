/*** 
 * @Date: 2022-04-22 14:59:25
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-22 14:59:26
 */

// 中心扩展法 O(n^2) / O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int start = 0, end = 0;
        for (int i = 0; i < len; i ++) {
            auto [left1, right1] = isPalindrome(s, i, i);
            auto [left2, right2] = isPalindrome(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    pair<int, int> isPalindrome(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left --;
            right ++;
        }
        return {left + 1, right - 1};
    }
};