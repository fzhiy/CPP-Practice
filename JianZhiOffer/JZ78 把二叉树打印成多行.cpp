/*** 
 * @Date: 2022-03-25 22:46:05
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-25 22:46:05
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
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> res;
            if (!pRoot) return res;
            queue<TreeNode*> que;
            que.push(pRoot);
            while (!que.empty()) {
                int size = que.size();
                vector<int> temp;
                while (size--) {
                    TreeNode* node = que.front();
                    temp.push_back(node->val);
                    que.pop();
                    if (node->left) que.push(node->left);
                    if (node->right) que.push(node->right);
                }
                res.push_back(temp);
            }
            return res;
        }
};