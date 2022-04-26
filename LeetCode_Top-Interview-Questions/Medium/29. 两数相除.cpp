/*** 
 * @Date: 2022-04-26 20:51:34
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-26 21:15:41
 */

/*
a / b 就是求有几个b能算出a - 余数。

如果a > b商一定是0

其他情况，逐个比较1,2,4,8,16,...,2n个b是不是超过a，如果超过了a就用剩余的重新再来。

比如a=-45, b=-2，

先1个，2个，4个，8个，16个，到32个会 < -45，得16
再用剩余的-13计算，1个，2个，4个，到8个会 < -13，得4
再用剩余的-5计算，1个，2个，到3个会 < -5，得2
剩余-1 < 2，得0
最后结果16+4+2+0=22
*/
class Solution {
public:
    int div(int a, int b) {
        if (a > b) return 0;
        int res = 1, step = b;
        while (a - step <= step) {
            step += step;
            res += res;
        }
        return res + div(a - step, b);
    }
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (divisor == 1) {
            return dividend;
        }
        bool flag = false;
        if (divisor > 0) {
            divisor = -divisor;
            flag = !flag;
        }
        if (dividend > 0) {
            dividend = -dividend;
            flag = !flag;
        }
        return flag ? -div(dividend, divisor) : div(dividend, divisor);
    }
};