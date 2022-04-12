/*** 
 * @Date: 2022-04-12 15:29:32
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-12 15:38:33
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            if (!i) continue;
            if (nums[i] == nums[i - 1]) {
                nums.erase(nums.begin() + i);
                i --;
            }
        }
        return nums.size();
    }
};