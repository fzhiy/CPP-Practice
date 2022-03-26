/*** 
 * @Date: 2022-03-26 11:12:14
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-26 11:13:22
 */

// 暴力 复杂度O(n^2)，会TLE。
// 归并排序。O(nlogn) / O(n)
// 参考讨论区：
// 如果两个区间为[4, 3] 和[1, 2]
// 那么逆序数为(4,1),(4,2),(3,1),(3,2)，同样的如果区间变为有序，比如[3,4] 和 [1,2]的结果是一样的，也就是说区间有序和无序结果是一样的。
// 但是如果区间有序会有什么好处吗？当然，如果区间有序，比如[3,4] 和 [1,2]
// 如果3 > 1, 显然3后面的所有数都是大于1， 这里为 4 > 1, 明白其中的奥秘了吧。所以我们可以在合并的时候利用这个规则。
class Solution {
public:
    const int mod = 1000000007;
    int InversePairs(vector<int> data) {
        int res = 0;
        vector<int> data_copy(data.size());
        merge_sort_core(data, data_copy, 0, data.size() - 1, res);
        return res;
    }
    void merge_sort_core(vector<int>& data, vector<int>& data_copy, int low, int high, int& res) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        int start1 = low, end1 = mid;
        int start2 = mid + 1, end2 = high;
        merge_sort_core(data, data_copy, start1, end1, res);
        merge_sort_core(data, data_copy, start2, end2, res);
        int index = low;
        while (start1 <= end1 && start2 <= end2) {
            if (data[start1] > data[start2]) {    // 构成逆序对
                data_copy[index++] = data[start2++];
                res = (res + mid - start1 + 1) % mod;    // 逆序对数量
            } else {
                data_copy[index++] = data[start1++];
            }
        }
        while (start1 <= end1) {
            data_copy[index++] = data[start1++];
        }
        while (start2 <= end2) {
            data_copy[index++] = data[start2++];
        }
        for (index = low; index <= high; index++) {
            data[index] = data_copy[index];
        }
    }
};