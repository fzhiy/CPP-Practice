/*** 
 * @Date: 2022-04-26 20:32:21
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-26 20:37:18
 */

/// dfs + 回溯
// O(n * 4), n表示字符串的长度
class Solution {
public:
    vector<char> v[10];
    void dfs(string digits, vector<string>& res, string temp, int index) {
        if (index == digits.size()) {
            res.push_back(temp);
            return ;
        }
        int idx = digits[index] - '0';
        for (int i = 0; i < v[idx].size(); i++) {
            dfs(digits, res, temp + v[idx][i], index + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        v[2] = {'a', 'b', 'c'};
        v[3] = {'d', 'e', 'f'};
        v[4] = {'g', 'h', 'i'};
        v[5] = {'j', 'k', 'l'};
        v[6] = {'m', 'n', 'o'};
        v[7] = {'p', 'q', 'r', 's'};
        v[8] = {'t', 'u', 'v'};
        v[9] = {'w', 'x', 'y', 'z'};
        vector<string> res;
        if (digits == "") return res;
        dfs(digits, res, "", 0);
        return res;
    }
};