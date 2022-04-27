/*** 
 * @Date: 2022-04-27 16:53:43
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-27 16:53:44
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), k = 0;
        for (int i = 0; i < n; i ++) {
            if (k < i) return false;    // 如果当前的最远的位置 小于 i
            k = max(k, i + nums[i]);    // i作为起点能够到达的右边最远的位置
        }
        return true;
    }
};