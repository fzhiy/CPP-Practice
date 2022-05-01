/*** 
 * @Date: 2022-05-01 16:50:25
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-05-01 16:53:52
 */

// 回溯 O(n * 2^n) / O(n)
class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            res.emplace_back(temp);
            return;
        }
        // 选择 nums[idx]
        temp.emplace_back(nums[idx]);
        dfs(res, temp, nums, idx + 1);
        temp.pop_back();
        // 不选择nums[idx]
        dfs(res, temp, nums, idx + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(res, temp, nums, 0);
        return res;
    }
};

// 迭代法  O(n * 2^n) / O(n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i ++) {
            temp.clear();
            for (int j = 0; j < n; j ++) {
                if (i & (1 << j)) {
                    temp.emplace_back(nums[j]);
                }
            }
            res.emplace_back(temp);
        }
        return res;
    }
};