/*** 
 * @Date: 2022-04-12 15:54:20
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-12 16:05:02
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = nums[0];
        for (auto x: nums) {
            sum += x;
            if (ans < sum) {
                ans = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
};

// 分治法 O(n) / O(logn) 栈空间
class Solution {
public:
    int maxSubArray(vector<int>& nums, int left, int right) {
        if (left > right) return INT_MIN;
        int mid = left + (right - left) / 2;
        int lmax = maxSubArray(nums, left, mid - 1);
        int rmax = maxSubArray(nums, mid + 1, right);
        int lsum = 0, rsum = 0;
        for (int sum = 0, i = mid - 1; i >= left; i --) {
            sum += nums[i];
            if (sum > lsum) {
                lsum = sum;
            }
        }
        for (int sum = 0, i = mid + 1; i <= right; i ++) {
            sum += nums[i];
            if (sum > rsum) {
                rsum = sum;
            }
        }
        return max(lsum + rsum + nums[mid], max(lmax, rmax));
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
};