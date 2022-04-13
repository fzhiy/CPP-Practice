/*** 
 * @Date: 2022-04-13 19:37:19
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 19:41:41
 */

// O(min(32, m)) , m 表示数n中 左数第一个1的位置
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32 && n > 0; i ++) {
            res |= (n & 1) << (31 - i);     // 逐位颠倒 然后累加
            n >>= 1;
        }
        return res;
    }
};