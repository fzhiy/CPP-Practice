/*** 
 * @Date: 2022-05-01 17:12:11
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-05-01 17:12:12
 */

class Solution {
public:
    static bool cmp(string& a, string& b) {
        return a + b < b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> strVec;
        for (int num: nums) {
            strVec.emplace_back(to_string(num));
        }
        sort(strVec.begin(), strVec.end(), cmp);
        string res;
        if (strVec.back() == "0") { // 特例 [0,0]
            return "0";
        }
        for (auto it = strVec.rbegin(); it != strVec.rend(); it ++) {
            res += (*it);
        }
        return res;
    }
};