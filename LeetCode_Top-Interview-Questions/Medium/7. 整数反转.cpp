/*** 
 * @Date: 2022-04-22 15:00:33
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-22 19:49:14
 */

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            if (ret < INT_MIN / 10 || ret > INT_MAX / 10) {
                return 0;
            }
            int mod = x % 10;
            ret = ret * 10 + mod;
            x /= 10;
        }
        return ret;
    }
};