/*** 
 * @Date: 2022-05-02 22:20:54
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-05-02 22:29:57
 */

// 如果nums中重复的数只出现两次，其他数出现一次，则可以 用求和 或者 位操作来写
// 这里是 重复的数可能出现两次及以上，那么可以看作是环形链表中求链表的环入口
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};