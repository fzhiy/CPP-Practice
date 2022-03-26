/*** 
 * @Date: 2022-03-26 09:40:53
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-26 09:45:21
 */

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param p int整型 
     * @param q int整型 
     * @return int整型
     */
    // O(logn) / O(1)， 利用了二叉搜索树 左子节点值 < 根节点值 < 右子节点值 的特点
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        TreeNode* cur = root;
        while (true) {
            // 这里不能是 声明临时变量val = cur->val，why？
            if (p < cur->val && q < cur->val) cur = cur->left;
            else if (p > cur->val && q > cur->val) cur = cur->right;
            else {    // p < val && q >= val || p >= val && q < val
                return cur->val;
            }
        } 
    }
};

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param p int整型 
     * @param q int整型 
     * @return int整型
     */
    // 递归形式 O(logn) / O(logn)
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        return dfs(root, p, q)->val;
    }
    TreeNode* dfs(TreeNode* root, int p, int q) {
        if (!root) return nullptr;
        if (root->val == p || root->val == q) {
            return root;
        }
        if (root->val > p && root->val > q) {
            return dfs(root->left, p, q);
        } else if (root->val < p && root->val < q) {
            return dfs(root->right, p, q);
        } else {
            return root;
        }
    }
};