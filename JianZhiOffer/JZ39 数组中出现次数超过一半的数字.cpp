/*** 
 * @Date: 2022-03-27 10:47:06
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-27 10:47:06
 */

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        // 方法1) 排序，直接输出中间值;
        // 方法2) map 计数，同时判断当前的数值出现次数是否超过数组长度的一半
        // 方法3 见代码 O(n) / O(1)
        int cnt = 0, res = INT_MAX;
        for (int& num : numbers) {
            if (cnt == 0) {
                cnt ++;
                res = num;
            } else if (res == num) {
                cnt ++;
            } else {
                cnt --;
            }
        }
        return res;
    }
};