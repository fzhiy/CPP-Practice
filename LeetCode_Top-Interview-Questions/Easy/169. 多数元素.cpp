/*** 
 * @Date: 2022-04-13 19:48:42
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 19:48:43
 */

// O(n) / O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (ans == nums[i]) {
                cnt ++;
            } else {
                cnt --;
                if (cnt == 0) {
                    ans = nums[i + 1];
                }
            }
        }
        return ans;
    }
};