/*** 
 * @Date: 2022-03-27 12:46:11
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-27 12:47:14
 */

// 双指针 O(n) / O(1)
// 因为数组是递增的，所以可以分别将left和right指向数组的首尾元素，然后根据两者之和与sum大小遍历
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int left = 0, right = array.size() - 1;
        while (left < right) {
            int num = array[left] + array[right];
            if (num < sum) {
                left ++;
            } else if (num > sum) {
                right --;
            } else {
                return vector<int>({array[left], array[right]});
            }
        }
        return vector<int>({});
    }
};