
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }
        int res = 0;
        for (int num : st) {
            int curNum = num;
            int conseNum = 1;
            if (!st.count(curNum - 1)) {
                while (st.count(curNum + 1)) {
                    ++ curNum;
                    ++ conseNum;
                }
            }
            res = max(res, conseNum);
        }
        return res;
    }
};