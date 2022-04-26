/*** 
 * @Date: 2022-04-26 20:33:44
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-26 20:44:29
 */

// 回溯法
class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>> &res, int first, int len) {
        if (first == len) {
            res.push_back(nums);
            return ;
        }
        for (int i = first; i < len; i ++) {
            swap(nums[first], nums[i]);
            dfs(nums, res, first + 1, len);
            swap(nums[first], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) {
            return res;
        }
        vector<int> temp;
        dfs(nums, res, 0, nums.size());
        return res;
    }
};