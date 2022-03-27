/*** 
 * @Date: 2022-03-27 10:51:02
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-27 10:53:34
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    // O(n) / O(n)
    string replaceSpace(string s) {
        // write code here
        string res("");
        for (char ch : s) {
            if (ch == ' ') {
                res += "%20";
            } else {
                res += ch;
            }
        }
        return res;
    }
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        // write code here
        char* res = new char[s.size() * 3];
        int index = 0;
        for (char& ch : s) {
            if (ch == ' ') {
                res[index++] = '%';
                res[index++] = '2';
                res[index++] = '0';
            } else {
                res[index++] = ch;
            }
        }
        return res;
    }
};
