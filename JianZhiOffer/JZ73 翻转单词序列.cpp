/*** 
 * @Date: 2022-03-20 11:35:16
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-20 11:40:47
 */

// 利用stringstream 将 str输入并存入vector, 然后利用双指针法翻转；最后转换成string类型返回
// O(n) / O(n) 
class Solution {
public:
    string ReverseSentence(string str) {
        stringstream ss(str);
        string s;
        vector<string> strVec;
        while (ss >> s) {
            strVec.push_back(s);
        }
        int n = strVec.size();
        for (int i = 0; i < n / 2; i ++) {
            swap(strVec[i], strVec[n - i - 1]);
        }
        s = "";
        for (string temp: strVec) {
            if (s != "") s += " ";
            s += temp;
        }
        return s;
    }
};

class Solution {
public:
    string ReverseSentence(string str) {
        // 预处理
        if (str.empty()) return str;
        
        stringstream ss(str);
        string s;
        vector<string> strVec;
        while (ss >> s) {
            strVec.push_back(s);
        }
        int n = strVec.size();
        for (int i = 0; i < n / 2; i ++) {
            swap(strVec[i], strVec[n - i - 1]);
        }
//         s = "";
//         for (string temp: strVec) {
//             if (s != "") s += " ";
//             s += temp;
//         }
//         return s;

        ostringstream oss;
        for (int i = 0; i < strVec.size() - 1; i ++) {
            oss << strVec[i] << " ";
        }
        oss << strVec.back();
        return oss.str();
    }
};