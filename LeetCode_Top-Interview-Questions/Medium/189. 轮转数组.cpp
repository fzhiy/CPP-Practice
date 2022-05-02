/*** 
 * @Date: 2022-05-02 21:48:01
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-05-02 22:06:41
 */

// k %= n, n表示nums数组的大小，直接做k次循环右移，TLE
// 使用额外一个数组空间  或 O(k)的空间
// 反转数组 O(n) / O(1)
class Solution {
public:
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l], nums[r]);
            ++l, --r;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};