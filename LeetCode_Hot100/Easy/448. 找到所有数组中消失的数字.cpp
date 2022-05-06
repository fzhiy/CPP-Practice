
// 使用额外空间，可以直接采用 哈希表计数法，O(n)空间, O(n)时间。
// 原地修改数组 避免使用额外计数数组。
// 因为题目数组元素nums[i] 范围是 [1, n]，因此将 (nums[i] - 1) % n 作为其下标, 代替计数数组

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (auto num: nums) {
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> res;
        for (int i = 0; i < n; i ++) {
            if (nums[i] <= n) {
                res.emplace_back(i + 1);
            }
        }
        return res;
    }
};