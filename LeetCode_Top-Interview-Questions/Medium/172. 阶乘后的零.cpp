/*** 
 * @Date: 2022-05-01 17:39:58
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-05-01 17:42:09
 */

// 10 = 2 * 5，阶乘后的零只可能由 2 * 5 得到
// 比如 n = 5,   5! = 1 * 2 * 3 * 4 * 5 = 120， 这里只含 1 个尾随0
// 比如 n = 10, 10! = 1 * 2 * 3 * 4 * 5 * (2 * 3) * 7 * (2 * 4) * 9 * (2 * 5)， 这里含 3 个尾随0
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            n /= 5;
            res += n;
        }
        return res;
    }
};