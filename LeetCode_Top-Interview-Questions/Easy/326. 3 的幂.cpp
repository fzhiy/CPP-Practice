/*** 
 * @Date: 2022-04-13 20:46:24
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 20:48:49
 */

// 3 ^ 19 = 1162261467, 32位 整数中 最大的3的幂，n是它的因子，则说明是3的幂
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};