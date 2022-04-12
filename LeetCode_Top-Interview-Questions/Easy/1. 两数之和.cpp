/*** 
 * @Date: 2022-04-12 14:18:15
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-12 14:35:05
 */
// https://leetcode.com/problems/two-sum/
// 纯暴力，TC: O(n ^ 2)
class Solution {
public:
    // 哈希表，{num : index}。 O(nlogn) / O(n)
    // 或者排序一下，然后用二分
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i ++) {
            if (mp.find(target - nums[i]) == mp.end()) {
                mp[nums[i]] = i;
            } else {
                return {mp[target - nums[i]], i};
            }
        }
        return {-1, -1};
    }
};