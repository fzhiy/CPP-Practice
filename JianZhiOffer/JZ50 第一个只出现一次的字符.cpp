/*** 
 * @Date: 2022-03-27 10:28:40
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-27 10:32:07
 */

// O(2n) / O(128)
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        vector<int> cnt(128, 0);
        for (int i = 0; i < str.size(); i ++) {
            cnt[str[i] - '0'] ++;
        }
        for (int i = 0; i < str.size(); i ++) {
            if (cnt[str[i] - '0'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

// bitset 存储二进制位
// O(2n) / O(128)
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        bitset<128> b1, b2;
        for (int i = 0; i < str.size(); i ++) {
            char ch = str[i];
            if (!b1[ch]) {
                b1[ch] = 1;
            } else if (b1[ch] && !b2[ch]) {
                b2[ch] = 1;
            }
        }
        for (int i = 0; i < str.size(); i ++) {
            if (b1[str[i]] == 1 && !b2[str[i]]) {
                return i;
            }
        }
        return -1;
    }
};