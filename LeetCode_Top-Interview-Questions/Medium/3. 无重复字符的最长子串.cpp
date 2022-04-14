/*** 
 * @Date: 2022-04-14 22:02:44
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-14 22:04:50
 */

// 滑动窗口 O(n) / O(sum) sum为所有字符的种类数量
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int res = 0, n = s.size();
        int r = 0;
        for (int i = 0; i < n; i ++) {  // 枚举子串的第一个元素
            if (i) {
                st.erase(s[i - 1]);
            }
            while (r < n && st.find(s[r]) == st.end()) {    // 直到出现重复的字符s[r]
                st.insert(s[r]);
                r ++;
            }
            res = max(res, r - i);
        }
        return res;
    }
};