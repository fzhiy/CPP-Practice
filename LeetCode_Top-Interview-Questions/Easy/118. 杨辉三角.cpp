/*** 
 * @Date: 2022-04-13 20:24:49
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 20:24:50
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; i++) {
            vector<int> temp(i + 1);
            for (int j = 0; j <= i; j ++) {
                if (!j || j == i) temp[j] = 1;
                else {
                    temp[j] = res[i - 1][j] + res[i - 1][j - 1];
                }
            }
            res[i] = temp;
        }
        return res;
    }
};