/*** 
 * @Date: 2022-03-27 12:00:11
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-27 12:00:25
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArrayTwo(vector<int>& array) {
        // write code here
        int low = 0, high = array.size() - 1;
        while (low < high) {
            while (low < high && array[low] % 2 == 1) {
                low ++;    // 从左往右找到第一个偶数的位置
            }
            while (high > low && array[high] % 2 == 0) {
                high --;    // 从右往左找到第一个奇数的位置
            }
            if (low < high) {
                swap(array[low], array[high]);
            }
        }
        return array;
    }
};