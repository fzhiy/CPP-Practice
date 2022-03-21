/*** 
 * @Date: 2022-03-21 09:21:21
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-21 09:23:27
 */

// 斐波那契数列变体
class Solution {
public:
    int rectCover(int number) {
        vector<int> dp(number + 1, 0);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= number; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[number];
    }
};

// O(n) / O(1)
class Solution {
public:
    int rectCover(int number) {
        if (number < 3) return number;
        int prev = 1, cur = 2;
        for (int i = 3; i <= number; i++) {
            int temp = prev + cur;
            prev = cur;
            cur = temp;
        }
        return cur;
    }
};