/*** 
 * @Date: 2022-04-13 20:25:43
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 20:29:10
 */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                res.emplace_back("FizzBuzz");
            } else if (i % 3 == 0) {
                res.emplace_back("Fizz");
            } else if (i % 5 == 0) {
                res.emplace_back("Buzz");
            } else {
                res.emplace_back(to_string(i));
            }
        }
        return res;
    }
};