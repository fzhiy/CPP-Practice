/*** 
 * @Date: 2022-04-27 17:02:39
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-27 17:03:41
 */

// O(nlogn) / O(logn) 所需空间为排序所需的额外空间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int first = intervals[0][0], second = intervals[0][1];
        int n = intervals.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i ++) {
            auto temp = intervals[i];
            if (second < temp[0]) {
                res.push_back({first, second});
                first = temp[0];
                second = temp[1];
            } else if (second < temp[1]) {  // [[1,4],[2,3]]
                second = temp[1];
            }
        }
        if (res.empty() || res.back()[1] != intervals[n - 1][1]) {
            res.push_back({first, second});
        }
        return res;
    }
};