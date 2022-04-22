/*** 
 * @Date: 2022-04-22 20:18:29
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-22 20:28:19
 */

// 1.00000
// -2147483648
// 使用long long 的原因是上面的这组数据 2147483648 不能用int表示。
// 快速幂乘法， O(logn) / O(1)
class Solution {
public:
    double quick_pow(double x, long long n) {
        double ans = 1.0;
        double x_copy = x;
        while (n > 0) {
            if (n & 1) {
                ans = ans * x_copy;
            }
            x_copy *= x_copy;
            n >>= 1;
        }
        return ans;
    }
    double myPow(double x, int n) {
        long long N = n;
        return N > 0 ? quick_pow(x, N) : 1.0 / quick_pow(x, -N);
    }
};