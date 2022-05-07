
// DP O(n) / O(n)
// 分别记录两边较高的柱子leftMax[i], rightMax[i] 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i ++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i --) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i ++) {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
        return res;
    }
};

// 双指针 O(n)/ O(1). 动态规划的进一步优化
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int res = 0, leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                res += (leftMax - height[left]);
                ++ left;
            } else {
                res += (rightMax - height[right]);
                -- right;
            }
        }
        return res;
    }
};