/*** 
 * @Date: 2022-04-13 20:11:15
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 20:17:35
 */
// O(n) / O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minprice = INT_MAX;
        int res = 0;
        for (int num : prices) {
            if (num < minprice) {
                minprice = num;
            } else if (num - minprice > res) {
                res = num - minprice;
            }
        }
        return res;
    }
};

// 单调栈 O(n) / O(n) 最坏空间复杂度
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> s;
        prices.emplace_back(0);
        int res = 0;
        for(int num : prices) {
            while (!s.empty() && num < s.back()) {  // 维护s 单调栈
                res = max(res, s.back() - s.front());
                s.pop_back();
            }
            s.emplace_back(num);
        }
        return res;
    }
};