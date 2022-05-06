
// 前缀和： 首先想到的是用两个数组 分别记录前缀乘积 和 后缀乘积。 但是复杂度O(n) / O(n)
// 优化：只记录前缀乘积，然后用一个变量 记录右边元素的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        int prefix = 1, suffix = 1;
        vector<int> res(size, 1);
        for (int i = 0; i < size; i ++) {
            res[i] *= prefix;
            res[size - i - 1] *= suffix;
            prefix *= nums[i];
            suffix *= nums[size - i - 1];
        }
        return res;
    }
};
