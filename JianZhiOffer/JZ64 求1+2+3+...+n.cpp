/*** 
 * @Date: 2022-03-20 14:14:15
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-20 14:17:34
 */

// 若不加限制，本题可以利用 遍历，递归 或者 求和公式来做
// 但是要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
// 所以这里 结合了 &&、递归 来解决这道题
// O(n) / O(n) 需要开辟n个局部变量
class Solution {
public:
    int Sum_Solution(int n) {
        n > 1 && (n += Sum_Solution(n - 1));
        return n;
    }
};