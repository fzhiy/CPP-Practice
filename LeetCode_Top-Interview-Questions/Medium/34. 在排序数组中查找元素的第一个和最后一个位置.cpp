/*** 
 * @Date: 2022-04-26 21:58:57
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-26 22:14:19
 */

// 二分法
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int n = nums.size(), ans = n;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
            // cout << l << " ";
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int second = binarySearch(nums, target, false) - 1;
        if (first <= second && second < nums.size() && nums[first] == target && nums[second] == target) {
            return {first, second};
        }
        return {-1, -1};
    }
};