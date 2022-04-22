/*** 
 * @Date: 2022-04-22 20:02:05
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-22 20:16:52
 */

// 先sort使得 数组有序，然后固定第一个数，求两数之和 = -nums[i]，并且判断 每个数是否重复，重复则跳过
// O(n^2) / O(logn) // 排序使用的额外空间
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n; i ++) {
            if (nums[i] > 0) {  // 第一个数 > 0，则不存在三元组满足三数之和为0
                return res;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {  // 保证三元组的第一个数不重复
                continue;
            }
            int l = i + 1, r = n - 1;
            // 双指针求两数之和
            while (l < r) {
                int temp = nums[l] + nums[r];
                if (temp + nums[i] < 0) {
                    ++ l;
                } else if (temp + nums[i] > 0){
                    -- r;
                } else {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    ++ l, -- r;
                    // 第二 和 第三个数也不能重复
                    while (l < r && nums[l] == nums[l - 1]) l ++;
                    while (r > l && nums[r] == nums[r + 1]) r --;
                }
            }
        }
        return res;
    }
};