/*** 
 * @Date: 2022-04-13 20:53:18
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 20:54:59
 */

// O(n) / O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i ++) {
            res ^= (i + 1) ^ nums[i];
        }
        return res;
    }
};