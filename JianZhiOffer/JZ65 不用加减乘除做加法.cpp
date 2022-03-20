/*** 
 * @Date: 2022-03-20 14:18:39
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-20 14:26:48
 */

// 加法 = 异或（无进位求和） + 位与&左移1位进位求和
// O(1) / O(1)
class Solution {
public:
    int Add(int num1, int num2) {
        while (num2 != 0) {
            int c = ((unsigned int)(num1 & num2)) << 1;    // 如果是负数,左移的话最后面会补1，所以要转化位unsigned
            num1 ^= num2;
            num2 = c;
        }
        return num1;
    }
};