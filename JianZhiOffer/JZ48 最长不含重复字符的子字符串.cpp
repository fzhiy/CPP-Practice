/*** 
 * @Date: 2022-03-21 11:22:53
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-21 11:28:19
 */
// 参考：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/solution/mian-shi-ti-48-zui-chang-bu-han-zhong-fu-zi-fu-d-9/
// O(n) / O(1)。 uMap最多存储128个（vector实现 或 unordered_map实现），因为字符的ASCII范围为 [0, 127]
// 这里 可以看作是 动态规划， 也可以看作是滑动窗口(i是左边界， j是有边界)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return int整型
     */
    int lengthOfLongestSubstring(string s) {
        // write code here
        vector<int> uMap(128, -1);
        int temp = 0, res = 0, i = -1;
        for (int j = 0; j < s.size(); j ++) {
            if (uMap[s[j]] != -1) {
                i = uMap[s[j]];
            }
            uMap[s[j]] = j;
            if (temp < j - i) {
                temp = temp + 1;
            } else {
                temp = j - i;
            }
            res = max(res, temp);
        }
        return res;
    }
};

