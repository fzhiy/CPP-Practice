/*** 
 * @Date: 2022-04-13 19:34:21
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 19:36:34
 */

// 阿里 以及另一个公司笔试中出过
// 考点：位操作 O(m) m 表示 整数n中1的位数 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            n = (n & (n - 1));  // n 为去掉最后一位1
            cnt ++;
        }
        return cnt;
    }
};
