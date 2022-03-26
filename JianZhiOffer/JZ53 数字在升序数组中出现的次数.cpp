/*** 
 * @Date: 2022-03-26 10:26:40
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-26 10:28:20
 */

// 二分法，先找下界，然后找上界 O(logn) / O(1)
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int left = 0, right = data.size();
        int lbound = 0, rbound = 0;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (data[mid] < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        lbound = left;    // 下界
        left = 0, right = data.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (data[mid] <= k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        rbound = left;
        return rbound - lbound;
    }
};

// 调用STL函数 upper_bound 和 lower_bound
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return upper_bound(data.begin(), data.end(), k) - lower_bound(data.begin(), data.end(), k);
    }
};