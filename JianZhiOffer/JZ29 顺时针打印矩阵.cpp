/*** 
 * @Date: 2022-03-22 09:56:46
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-22 09:56:47
 */
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, up = 0, down = m - 1;
        while (true) {
            // 最上面的一行
            for (int j = left; j <= right; j ++) {
                res.push_back(matrix[up][j]);
            }
            up ++;    // 向下
            if (up > down) break;
            // 最右边的一行
            for (int i = up; i <= down; i ++) {
                res.push_back(matrix[i][right]);
            }
            right --;    //向左
            if (left > right) break;
            for (int j = right; j >= left; j --) {
                res.push_back(matrix[down][j]);
            }
            down --;    // 向上
            if (up > down) break;
            for (int i = down; i >= up; i--) {
                res.push_back(matrix[i][left]);
            }
            left ++;    // 向右
            if (left > right) break;
        }
        return res;
    }
};