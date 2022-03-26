/*** 
 * @Date: 2022-03-26 10:47:32
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-26 10:47:33
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int findNthDigit(int n) {
        // write code here
        // 0
        // 1 ~ 9      | digit = 1 start = 1 * 1       count = 1 * 9 * 1
        // 10 ~ 99    | digit = 2 start = 1 * 10      count = 10 * 9 * 2
        // 100 ~ 999  | digit = 3 start = 1 * 10 * 10 count = 100 * 9 * 3
        if (n <= 0) return 0;
        long start = 1, digit = 1, count = 9;
        while (n > count) {
            n -= count; // 减去当前位数的总长度
            start *= 10;
            digit += 1;
            count = start * 9 * digit;
        }
        // 找到当前位数的区间
        string num = to_string(start + (n - 1) / digit);
        int idx = (n - 1) % digit;
        return num[idx] - '0';
    }
};