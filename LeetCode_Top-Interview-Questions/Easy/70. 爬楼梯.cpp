/*** 
 * @Date: 2022-04-13 16:27:08
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 16:29:12
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        int x0 = 1, x1 = 2;
        for (int i = 3; i <= n; i ++) {
            int temp = x0 + x1;
            x0 = x1;
            x1 = temp;
        }
        return x1;
    }
};