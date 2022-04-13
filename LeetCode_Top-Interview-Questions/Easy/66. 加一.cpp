/*** 
 * @Date: 2022-04-13 15:47:51
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 16:08:18
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0, n = digits.size();
        digits[n - 1] ++;
        for (int i = n - 1; i >= 0; i --) {
            int temp = carry;
            carry = (digits[i] + carry) / 10;
            digits[i] = (digits[i] + temp) % 10;
        }
        if (carry) {
            digits.resize(n + 1);
            for (int i = n; i > 0; i --) {
                digits[i] = digits[i - 1];
            }
            digits[0] = carry;
        }
        return digits;
    }
};

// 更进一步，判断+1后 对10取余，判断是否为0
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            digits[i] = (digits[i] + 1) % 10;
            if (digits[i] != 0) {
                return digits;
            }
        }
        if (digits[0] == 0) {
            digits.insert(begin(digits), 1);
        }
        return digits;
    }
};