/*** 
 * @Date: 2022-04-13 17:07:21
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 17:15:49
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversal(root, res);
        return res;
    }
    void inorderTraversal(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorderTraversal(root->left, res);
        res.push_back(root->val);
        inorderTraversal(root->right, res);
    }
};

// 迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while (!stk.empty() || p) {
            if (p) {
                stk.push(p);
                p = p->left;
            } else {
                p = stk.top();
                stk.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};