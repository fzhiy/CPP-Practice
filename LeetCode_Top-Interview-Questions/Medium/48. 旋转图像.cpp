/*** 
 * @Date: 2022-04-27 15:27:07
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-27 15:32:34
 */

/// 两次对称： O(n^2) / O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 上下对称交换
        for (int i = 0; i < n / 2; i ++) {
            for (int j = 0; j < n; j ++) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 关于主对角线对称
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

// 法2：选中4个元素，依次旋转交换