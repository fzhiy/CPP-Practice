/*** 
 * @Date: 2022-03-20 13:41:22
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-20 13:41:23
 */

// n & (n - 1) 去掉最右边的一个1
class Solution {
public:
     int  NumberOf1(int n) {
         int cnt = 0;
         while (n) {
             cnt ++;
             n = (n & (n - 1));
         }
         return cnt;
     }
};