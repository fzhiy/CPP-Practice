/*** 
 * @Date: 2022-04-26 21:48:28
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-26 21:58:34
 */

// 最简单的做法，依次遍历，O(n)
// 进阶：二分法（数组升序），O(logn)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, n = nums.size(), r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target <= nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
