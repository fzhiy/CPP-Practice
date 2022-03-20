/*** 
 * @Date: 2022-03-20 14:03:30
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-20 14:09:24
 */

// 直接做法：哈希表，但是时间空间都不是最优
// 利用 ^ 异或运算。只有一个数出现一次的时候，初始值res=0, 直接对所有元素遍历异或 即可得到出现一次的数；
// 那么现在是两个出现一次的数，遍历异或的结果是这两个数的异或值，那么需要将这两个数区分开来（分组）；
// 计算机存储整数都是二进制存储的，假设两个出现一次的值是2, 6, 2 ^ 6 = (10) ^ (110) = 100。那么找到分组的数就是4。
// 然后按分组分别求出出现一次的数即可
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        int temp = 0;
        for (int& num: array) {
            temp ^= num;
        }
        int x = 1;
        while ((temp & x) == 0) {
            x <<= 1;
        }
        int a = 0, b = 0;
        for (int& num: array) {
            if ((num & x) == 0) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        if (a > b) swap(a, b);
        return {a, b};
    }
};