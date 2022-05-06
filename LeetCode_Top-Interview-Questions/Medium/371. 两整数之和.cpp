
// 加法不允许用 加减法，转化为 二进制无进位加法 和 二进制进位加法。
// 用 unsigned int 转化，因为负数不允许左移
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};