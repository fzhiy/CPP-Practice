/*** 
 * @Date: 2022-03-26 10:47:49
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-26 10:47:49
 */

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array[0].size() == 0) {
            return false;
        }
        int row = array.size() - 1;
        int col = 0;
        int n = array.size(), m = array[0].size();
        while (col < m && row >= 0) {
            if (array[row][col] == target) {
                return true;
            } else if (array[row][col] > target) {
                row --;
            } else {
                col++;
            }
        }
        return false;
    }
};