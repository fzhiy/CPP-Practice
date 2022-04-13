/*** 
 * @Date: 2022-04-13 16:08:46
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 16:26:45
 */

// 换底公式， 用 e 作为底
// 法2: 二分法
// 法3：牛顿迭代法 O(log x) / O(1)
/*
y = f(x) = x^2 - C。 用C表示待求出的哪个整数
牛顿迭代的本质是 借助泰勒级数，从初始值开始快速向零点逼近。
迭代方程 x_{i+1} = 1/2 * (x_i + C/x_i)

选择 x_0 = C为初始值，零点有两个 即正负根号C，但是要求的是正的那个
参考：https://leetcode-cn.com/problems/sqrtx/solution/x-de-ping-fang-gen-by-leetcode-solution/
*/
// 换底 O(1) / O(1)
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int ans = exp(0.5 * log(x));
        return (long long)(ans + 1) * (ans + 1) <= x ? (ans + 1) : ans;
    }
};

// 二分法 O(log x) / O(1)
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x; 
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
// 牛顿迭代法 O(log x) / O(1)
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        double C = x, x0 = x, xi;
        while (true) {
            xi = 0.5 * (x0 + C / x0);
            if (fabs(xi - x0) < 1e-6) {
                break;
            }
            x0 = xi;
        }
        return (int) x0;
    }
};
