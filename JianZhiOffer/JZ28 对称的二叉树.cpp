/*** 
 * @Date: 2022-03-25 22:03:15
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-25 22:41:51
 */

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
// O(n) / O(n)
// 从 `子树层面` 来检查是否是对称的
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        return isSymmetrical(pRoot, pRoot);
    }
    bool isSymmetrical(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        return root1->val == root2->val && 
            isSymmetrical(root1->left, root2->right) && 
            isSymmetrical(root1->right, root2->left);
    }
};

// 从 `层序遍历` 来检查是否是对称的
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (!pRoot) return true;
        
        queue<TreeNode*> que;
        que.push(pRoot);
        que.push(pRoot);
        while (!que.empty()) {
            TreeNode* node1 = que.front();
            que.pop();
            TreeNode* node2 = que.front();
            que.pop();
            if (!node1 && !node2) { // 都为空
                continue;
            }
            if (!node1 || !node2 || node1->val != node2->val) { // 只有一个子节点为空 或者节点值不同
                return false;
            }
            que.push(node1->left), que.push(node2->right);
            que.push(node1->right), que.push(node2->left);
        }
        return true;
    }
};
