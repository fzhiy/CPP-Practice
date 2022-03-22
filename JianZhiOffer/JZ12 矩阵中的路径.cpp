/*** 
 * @Date: 2022-03-22 10:59:17
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-22 10:59:18
 */

// O(m * n) / O(m * n) 最差情况下对每个元素都开辟了一个空间。
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    bool backtrack(vector<vector<char>>& matrix, string word, int index, int x, int y) {
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[x][y] != word[index]) {
            return false;
        }
        if (index == word.size() - 1) {
            return true;
        }
        char temp = matrix[x][y];
        matrix[x][y] = '.';
        bool res = backtrack(matrix, word, 1 + index, x + 1, y) ||
                   backtrack(matrix, word, 1 + index, x - 1, y) ||
                   backtrack(matrix, word, 1 + index, x, y + 1) ||
                   backtrack(matrix, word, 1 + index, x, y - 1);
        matrix[x][y] = temp;
        return res;
    }
    
    bool hasPath(vector<vector<char> >& matrix, string word) {
        // write code here
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        bool flag = false;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (backtrack(matrix, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
};