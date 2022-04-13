/*** 
 * @Date: 2022-04-13 20:49:12
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 20:53:02
 */

// O(n) / O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        while (r < n) {
            if (nums[r]) {  
                swap(nums[l], nums[r]); // 交换右指针指向的非零元素和左指针指向的零元素
                l ++;
            }
            r ++;
        }
    }
};