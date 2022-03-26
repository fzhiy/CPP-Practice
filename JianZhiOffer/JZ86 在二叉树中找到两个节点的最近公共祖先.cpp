/*** 
 * @Date: 2022-03-26 10:06:36
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-26 10:09:53
 */

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    // 层序遍历：两个节点元素值o1 o2都遍历到了就结束遍历，遍历过程中记录o1和o2及其祖先节点的父节点；
    // 然后将o1的祖先节点都加入集合，通过前面的map找o2的祖先节点是否存在于集合ancestors中，存在则返回，
    // 否则迭代寻找o2与o1的最近公共祖先节点
    // O(n) / O(n), 最坏情况下时间复杂度为O(n)
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        unordered_map<int, int> parent;
        parent[root->val] = INT_MIN;    // 根节点没有父节点，默认值为INT_MIN
        queue<TreeNode*> que;
        que.push(root);
        while (parent.find(o1) == parent.end() || parent.find(o2) == parent.end()) {
            TreeNode* node = que.front();
            que.pop();
            if (node->left) {
                que.push(node->left);
                parent[node->left->val] = node->val;
            }
            if (node->right) {
                que.push(node->right);
                parent[node->right->val] = node->val;
            }
        }
        set<int> ancestors;
        while (parent.find(o1) != parent.end()) {
            ancestors.insert(o1);
            o1 = parent[o1];    // 将o1与o1的祖先节点都加入到 集合 ancestors中
        }
        while (!ancestors.count(o2)) {    
            // 查找集合 ancestors中是否存在o2的祖先节点，最先找到的一个祖先节点即为最近公共祖先
            o2 = parent[o2];
        }
        return o2;
    }
};

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    // O(n) / O(n)
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        return dfs(root, o1, o2)->val;
    }
    TreeNode* dfs(TreeNode* root, int p, int q) {
        if (!root) return nullptr;
        if (root->val == p || root->val == q) {
            return root;
        }
        auto left = dfs(root->left, p, q);
        auto right = dfs(root->right, p, q);
        if (left == nullptr) return right;
        else if (right == nullptr) return left;
        else return root;
    }
};