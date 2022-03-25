/*** 
 * @Date: 2022-03-25 21:41:46
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-25 21:41:46
 */

// O(n) / O(n) n 为 二叉树节点的个数
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return getDepth(pRoot) != -1;
    }
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        int lDepth = getDepth(root->left);
        if (lDepth == -1) return -1;
        int rDepth = getDepth(root->right);
        if (rDepth == -1) return -1;
        int sub = abs(lDepth - rDepth);
        if (sub > 1) return -1;    // 左右子树的高度差 大于1，则已经不是平衡树了
        return max(lDepth, rDepth) + 1;
    }
};