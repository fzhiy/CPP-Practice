/*** 
 * @Date: 2022-04-22 20:00:58
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-22 20:00:58
 */

// 双指针。 枚举边界 l 和 r，向中间靠拢
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l <= r) {
            int minx = min(height[l], height[r]);
            int area = minx * (r - l);
            ans = max(ans, area);
            if (height[l] >= height[r]) {
                --r;
            } else {
                ++l;
            }
        }
        return ans;
    }
};