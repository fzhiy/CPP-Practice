/*** 
 * @Date: 2022-04-02 10:38:02
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-02 10:38:04
 */
// 快速幂乘法计算 3^n. O(logn) / O(logn)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number long长整型 
     * @return long长整型
     */
    const int mod = 998244353;
    long long q_power(long long n) {
        // O(logn) 求 3^n
        if (n == 0) return 1;
        if (n == 1) return 3;
        long long res = q_power(n / 2);
        if (n % 2 == 0) {
            return res * res % mod;
        } else {
            return 3 * res * res % mod;
        }
    }
    long long cutRope(long long number) {
        // write code here
        if (number < 4) return number - 1;
        long long cnt = number / 3;
        if (number % 3 == 0) {
            return q_power(cnt);
        } else if (number % 3 == 1) {
            return 2 * 2 * q_power(cnt - 1) % mod;
        } else {
            return 2 * q_power(cnt) % mod;
        }
    }
};