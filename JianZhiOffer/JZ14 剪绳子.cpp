/*** 
 * @Date: 2022-03-29 17:40:48
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-29 17:44:12
 */

class Solution {
public:
    int cutRope(int number) {
        vector<int> dp(number + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= number; i ++) {
            for (int j = 2; j < i; j ++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[number];
    }
};

class Solution {
public:
    int cutRope(int number) {
        if (number < 4) return number - 1;
        int a = number / 3, b = number % 3;
        if (b == 0) return pow(3, a);
        if (b == 1) return pow(3, a - 1) * 4;
        return pow(3, a) * 2;
    }
};