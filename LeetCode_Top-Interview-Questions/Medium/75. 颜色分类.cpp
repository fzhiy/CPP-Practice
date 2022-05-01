/*** 
 * @Date: 2022-05-01 16:04:59
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-05-01 16:31:45
 */

// 最简单的调用排序函数
// 单指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p++]);
            }
        }
        for (int i = p; i < nums.size(); i ++) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p++]);
            }
        }
    }
};

// 进一步，根据题目，只有三种颜色，那么只要把0往左边丢，2往右边丢，即为所求
// 双指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1;
        for (int i = 0; i <= p2; i ++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p0++]);
            } else if (nums[i] == 2) {
                swap(nums[i], nums[p2--]);
                if (nums[i] != 1) { // 如果交换过来的不是1，而是0或2，此时需要再次进行下一次交换，所以--i实现回退
                    -- i;
                }
            }
        }
    }
};