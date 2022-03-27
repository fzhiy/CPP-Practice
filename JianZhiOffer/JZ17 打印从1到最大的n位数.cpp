/*** 
 * @Date: 2022-03-27 12:42:18
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-27 12:42:28
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 最大位数
     * @return int整型vector
     */
    vector<int> printNumbers(int n) {
        // write code here
        vector<int> res;
        int num = 1;
        for (int i = 0; i < n; i++) {
            num *= 10;
        }
        for (int i = 1; i < num; i++) {
            res.push_back(i);
        }
        return res;
    }
};