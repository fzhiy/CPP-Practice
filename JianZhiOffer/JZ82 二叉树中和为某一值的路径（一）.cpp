/*** 
 * @Date: 2022-03-25 18:57:26
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-25 18:57:27
 */

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if (!root) return false;
        return dfs(root, sum);
    }
    bool dfs(TreeNode* root, int sum) {
        if (!root) return false;
        sum -= root->val;
        if (sum == 0 && !root->left && !root->right) {
            return true;
        }
        bool left = dfs(root->left, sum);
        bool right = dfs(root->right, sum);
        return left || right;
    }
};