/*** 
 * @Date: 2022-03-23 22:05:03
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-24 09:59:31
 */

/// DFS / BFS
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
// DFS, O(n) / O(n)
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (!pRoot) return 0;
        int lDepth = TreeDepth(pRoot->left);
        int rDepth = TreeDepth(pRoot->right);
        return max(lDepth, rDepth) + 1;
    }
};

// BFS O(n) / O(n)
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
    int TreeDepth(TreeNode* pRoot) {
        if (!pRoot) return 0;
        queue<TreeNode*> que;
        que.push(pRoot);
        int ans = 0;
        while (!que.empty()) {
            int n = que.size();
            if (n) ans ++;
            while (n --) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return ans;
    }
};