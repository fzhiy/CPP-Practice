/*** 
 * @Date: 2022-03-24 12:20:48
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-24 12:20:48
 */
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2) return false;
        return dfs(pRoot1, pRoot2) ||
            HasSubtree(pRoot1->left, pRoot2) || 
            HasSubtree(pRoot1->right, pRoot2);
    }
    bool dfs(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot2) return true;
        if (!pRoot1 || pRoot1->val != pRoot2->val) return false;
        return dfs(pRoot1->left, pRoot2->left) && dfs(pRoot1->right, pRoot2->right);
    }
};