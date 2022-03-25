/*** 
 * @Date: 2022-03-25 23:11:27
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-25 23:11:28
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
// O(n) / O(n) 递归栈空间占用了O(n)
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree) return nullptr;
        TreeNode* p = pRootOfTree;
        while (p->left) {
            p = p->left;
        }
        TreeNode* prevNode = nullptr;
        inOrder(pRootOfTree, prevNode);
        return p;
    }
    void inOrder(TreeNode* root, TreeNode*& prevNode) {
        if (!root) return;
        inOrder(root->left, prevNode);
        root->left = prevNode;
        if (prevNode) {
            prevNode->right = root;
        }
        prevNode = root;    // 更新prevNode，作为下一个节点的前驱节点
        inOrder(root->right, prevNode);
    }
};