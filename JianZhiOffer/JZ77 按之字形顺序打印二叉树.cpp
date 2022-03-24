/*** 
 * @Date: 2022-03-24 10:00:49
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-24 10:18:10
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
// 层序遍历都是从左往右，而这里是相邻层遍历需要反向。可以reverse反转数组
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (!pRoot) return res;
        queue<TreeNode*> que;
        que.push(pRoot);
        int k = 0;
        while (!que.empty()) {
            vector<int> tempIVec;
            int n = que.size();
            while (n --) {
                TreeNode* node = que.front();
                que.pop();
                tempIVec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            if (k & 1) reverse(tempIVec.begin(), tempIVec.end());
            ++k;
            res.push_back(tempIVec);
        }
        return res;
    }
};