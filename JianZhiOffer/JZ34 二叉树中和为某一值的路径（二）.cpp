/*** 
 * @Date: 2022-03-25 21:02:52
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-25 21:02:53
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
// O(n) / O(n)
class Solution {
public:
    void dfs(TreeNode* root, int excectNumber, vector<int>& temp, vector<vector<int>>& res) {
        temp.push_back(root->val);
        if (excectNumber == root->val && root->left == nullptr && root->right == nullptr) {
            res.push_back(temp);
        }
        if (root->left) {
            dfs(root->left, excectNumber - root->val, temp, res);
        }
        if (root->right) {
            dfs(root->right, excectNumber - root->val, temp, res);
        }
        temp.pop_back();    // 走到这里，需要回溯。当前的root节点不需要了
    }
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> temp;
        dfs(root, expectNumber, temp, res);
        return res;
    }
};