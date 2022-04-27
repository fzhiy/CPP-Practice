/*** 
 * @Date: 2022-04-27 15:33:36
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-27 15:54:56
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9], col[9][9], subbox[3][3][9];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(subbox, 0, sizeof(subbox));
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') continue;
                int index = board[i][j] - '0' - 1;
                row[i][index] ++;
                col[j][index] ++;
                subbox[i / 3][j / 3][index] ++;
                if (row[i][index] > 1 || col[j][index] > 1 || subbox[i / 3][j / 3][index] > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};