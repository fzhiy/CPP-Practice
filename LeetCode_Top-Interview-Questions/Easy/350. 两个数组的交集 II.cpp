/*** 
 * @Date: 2022-04-13 20:41:14
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 20:43:48
 */

// 进阶：

// 如果给定的数组已经排好序呢？你将如何优化你的算法？
// 如果 nums1 的大小比 nums2 小，哪种方法更优？
// 如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii

// 进阶1： 如果已经排好序了，就用双指针，O(m + n) / 空间复杂度O(min(m, n))
// 进阶2：哈希表法， 如下
// 进阶3：不能一次加载所有元素道内存中，外部排序的最佳方法应该是 归并排序。

// O(m + n) / O(min(m, n))
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> mp;
        for (int num : nums1) {
            mp[num] ++;
        }
        vector<int> res;
        for (int num : nums2) {
            if (mp.count(num)) {
                res.emplace_back(num);
                mp[num] --;
                if (mp[num] == 0) {
                    mp.erase(num);
                }
            }
        }
        return res;
    }
};