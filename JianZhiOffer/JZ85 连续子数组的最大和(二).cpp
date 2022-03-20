/*** 
 * @Date: 2022-03-20 14:49:04
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-20 14:49:05
 */

// 动态规划+记录始末位置。O(n) / O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        // write code here
        if (array.size() == 0) return array;
        int n = array.size();
        int maxSum = array[0], start_temp = 0, end_temp = 0;
        int start = 0, end = 0, sum = array[0];
        for (int i = 1; i < n; i++) {
            if (sum >= 0) {
                sum += array[i];
                end_temp = i;
            } else {
                sum = array[i];
                start_temp = i;
                end_temp = i;
            }
            if (sum >= maxSum) {
                maxSum = sum;
                start = start_temp;
                end = end_temp;
            }
        }
        vector<int> res(end - start + 1);
        for (int i = 0; i < end - start + 1; i++) {
            res[i] = array[start + i];
        }
        return res;
    }
};