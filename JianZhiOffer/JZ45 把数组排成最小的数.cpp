/*** 
 * @Date: 2022-03-27 13:11:37
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-27 13:11:37
 */

// O(nlogn) / O(n)
class Solution {
public:
    //加static的原因：类成员函数有隐藏的this指针,static 可以去this指针
    bool static cmp(string a, string b) {
        return a + b < b + a;
    }
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strVec;
        for (auto& num : numbers) {
            strVec.push_back(to_string(num));
        }
        sort(strVec.begin(), strVec.end(), cmp);
        string res("");
        for (auto& s : strVec) {
            res += s;
        }
        return res;
    }
};