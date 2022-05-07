
/*
算法过程
标准的“下一个排列”算法可以描述为：

1) 从后向前查找第一个相邻升序的元素对 (i,j)，满足 A[i] < A[j]。此时 [j,end) 必然是降序
2) 在 [j,end) 从后向前查找第一个满足 A[i] < A[k] 的 k。A[i]、A[k] 分别就是上文所说的「小数」、「大数」
3) 将 A[i] 与 A[k] 交换
4) 可以断定这时 [j,end) 必然是降序，逆置 [j,end)，使其升序
5) 如果在步骤 1 找不到符合的相邻元素对，说明当前 [begin,end) 为一个降序顺序，则直接跳到步骤 4
该方法支持数据重复，且在 C++ STL 中被采用。

作者：imageslr
链接：https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return ;
        int i = n - 2, j = n - 1, k = n - 1;
        // 从后往前找到第一个相邻元素对(i, j), 使得nums[i] < nums[j]
        while (i >= 0 && nums[i] >= nums[j]) {
            i --;
            j --;
        }
        if (i >= 0) {   // 不是最后一个排列
            // 此时nums[j, ..., k] 中的元素是降序的
            while (k >= j && nums[i] >= nums[k]) {
                k --;
            }
            // 交换 nums[i] 和 nums[k]
            swap(nums[i], nums[k]);
        }
        // 反转 nums[j, ..., end]
        for (int i = j, j = n - 1; i < j; i ++, j --) {
            swap(nums[i], nums[j]);
        }
    }
};