/*** 
 * @Date: 2022-04-12 15:38:55
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-12 15:51:09
 */

// O(n * m) / O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "" || haystack == needle) return 0;
        int l1 = haystack.size(), l2 = needle.size();
        for (int i = 0; i <= l1 - l2; i ++) {
            int r = i, j = 0;
            while (j < l2 && haystack[r] == needle[j]) {
                r ++;
                j ++;
            }
            if (j == l2) {
                return i;
            }
        }
        return -1;
    }
};