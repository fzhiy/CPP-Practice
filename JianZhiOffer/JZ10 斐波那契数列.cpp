/*** 
 * @Date: 2022-03-21 09:07:01
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-21 09:07:02
 */
class Solution {
public:
    int Fibonacci(int n) {
        int prev = 1, cur = 1;
        for (int i = 3; i <= n; i++){
            int temp = prev + cur;
            prev = cur;
            cur = temp;
        }
        return cur;
    }
};