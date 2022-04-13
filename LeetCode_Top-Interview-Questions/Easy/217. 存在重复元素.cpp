/*** 
 * @Date: 2022-04-13 21:17:32
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 21:18:40
 */

// 哈希表 O(n) / O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int num: nums) {
            if (st.count(num)) {
                return true;
            }
            st.insert(num);
        }
        return false;
    }
};