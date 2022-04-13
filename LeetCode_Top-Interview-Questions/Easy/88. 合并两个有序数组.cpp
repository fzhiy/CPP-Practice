/*** 
 * @Date: 2022-04-13 16:29:21
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 16:43:28
 */

// 题目中nums1 后面部分的元素都是0. 这里我们可以从后面开始存储
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1, i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (nums2[j] > nums1[i]) {
                nums1[k --] = nums2[j --];
            } else {
                nums1[k --] = nums1[i --];
            }
        }
        while (j >= 0) {
            nums1[k --] = nums2[j --];
        }
    }
};