/*** 
 * @Date: 2022-04-26 21:29:41
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-26 21:33:57
 */

// 规律：剩余未使用的左括号数量一定 小于等于 右括号的数量
class Solution {
public:
    void generateParenthesis(vector<string>& res, string str, int left, int right) {
        if (left == right && left == 0) {
            // 左右括号刚好用完
            res.push_back(str);
            return ;
        }
        if (left < 0 || right < 0) {
            return;
        }
        if (left == right) { // 下一个必须用左括号，否则 无效
            generateParenthesis(res, str + "(", left - 1, right);
        } else if (left < right) {  // 只有 left < right时才有效， left > right时 一定无效 
            if (left > 0)  {    // 有左括号可用
                generateParenthesis(res, str + "(", left - 1, right);
            }
            generateParenthesis(res, str + ")", left, right - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis(res, "", n, n);
        return res;
    }
};

// 第二种方法：成对组装
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1) {
            return {"()"};
        }
        vector<string> res;
        unordered_set<string> st;
        for (auto& s: generateParenthesis(n - 1)) {
            for (int i = 0; i < 2 * (n - 1); i ++) {
                string temp = s.substr(0, i) + "()" + s.substr(i, 2 * (n - 1));
                if (st.find(temp) == st.end()) {
                    st.insert(temp);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};