/*** 
 * @Date: 2022-04-13 19:12:15
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 19:37:06
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root, root);
    }
    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root), q.push(root);
        while (!q.empty()) {
            TreeNode* u = q.front();
            q.pop();
            TreeNode* v = q.front();
            q.pop();
            if (!u && !v) continue;
            if (!u || !v || (u->val != v->val)) {
                return false;
            }
            q.push(u->left), q.push(v->right);
            q.push(u->right), q.push(v->left);
        }
        return true;
    }
};