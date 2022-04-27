/*** 
 * @Date: 2022-04-27 16:31:24
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-27 16:48:10
 */

// 按层读 O(n * m) / O(1) 不改变原数组
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int top = 0, down = m - 1, left = 0, right = n - 1;
        while (top <= down && left <= right) {
            // 右
            for (int j = left; j <= right; j ++) {
                res.push_back(matrix[top][j]);
            }
            // 下
            for (int i = top + 1; i <= down; i ++) {
                res.push_back(matrix[i][right]);
            }
            if (top < down && left < right) {
                // 左
                for (int j = right - 1; j >= left; j --) {
                    res.push_back(matrix[down][j]);
                }
                // 上
                for (int i = down - 1; i >= top + 1; i--) {
                    res.push_back(matrix[i][left]);
                }
            }
            left++, right--, top++, down--;
        }
        return res;
    }
};

// 标记数组，O(n * m) / O(n * m) 不改变原数组
// 若允许改变原数组， O(n * m) / O(1)