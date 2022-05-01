/*** 
 * @Date: 2022-05-01 15:34:34
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-05-01 16:04:22
 */

// O(n klogk) / O(n * k), 排序需要klogk的复杂度，n表示strs的大小，k表示字符串的长度
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto& str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> res;
        for (auto it = mp.begin(); it != mp.end(); it ++) {
            res.emplace_back(it->second);
        }
        return res;
    }
};

// 将strs的字符串编码，比如 baaacc 编码为 a2b1c3，然后放进字典
// O(n * (k + sum)) / O(n * k), sum表示字符串中字符的种类
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto& str: strs) {
            string number;
            vector<int> num(26, 0);
            for (char ch : str) {
                num[ch - 'a'] ++;
            }
            for (int i = 0; i < 26; i ++) {
                if (num[i]) {
                    number += char('a' + i) + to_string(num[i]);
                }
            }
            mp[number].emplace_back(str);
        }
        vector<vector<string>> res;
        for (auto it = mp.begin(); it != mp.end(); it ++) {
            res.emplace_back(it->second);
        }
        return res;
    }
};
