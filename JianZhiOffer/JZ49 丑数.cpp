/*** 
 * @Date: 2022-03-27 13:07:17
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-27 13:07:17
 */

// O(n) / O(n)
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index < 6) return index;
        vector<int> res(index);
        res[0] = 1;
        int num2 = 0, num3 = 0, num5 = 0;
        for (int i = 1; i < index; i ++) {
            res[i] = min(2 * res[num2], min(3 * res[num3], 5 * res[num5]));
            if (res[i] == 2 * res[num2]) num2 ++;
            if (res[i] == 3 * res[num3]) num3 ++;
            if (res[i] == 5 * res[num5]) num5 ++;
        }
        return res[index - 1];
    }
};