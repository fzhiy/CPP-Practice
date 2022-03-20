/*** 
 * @Date: 2022-03-20 13:45:01
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-20 13:52:24
 */
// 1）暴力；2）快速幂乘法（分为递归 与 迭代）
// 暴力：O(n) / O(1)
class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent < 0) {
            base = 1/ base;
            exponent = - exponent;
        }
        double res = 1.0;
        for (int i =0; i < exponent; i++) {
            res *= base;
        }
        return res;
    }
};

// 快速幂 递归 O(logn) / O(logn) 递归栈
class Solution {
public:
    double q_power(double b, int n) {
        if (n == 0) {
            return 1.0;
        }
        double res = q_power(b, n >> 1);
        res *= res;
        return (n & 1) == 1 ? (res * b) : res; 
    }
    double Power(double base, int exponent) {
        if (exponent < 0) {
            base = 1/ base;
            exponent = - exponent;
        }
        return q_power(base, exponent);
    }
};

// 迭代 O(logn) / O(1)
class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent < 0) {
            base = 1/ base;
            exponent = - exponent;
        }
        double res = 1.0;
        while (exponent) {
            if (exponent & 1) {    // 二进制位数是1
                res *= base;
            }
            exponent >>= 1;
            base *= base;
        }
        return res;
    }
};