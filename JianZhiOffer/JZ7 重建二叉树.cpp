/*** 
 * @Date: 2022-03-24 10:49:23
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-24 10:49:23
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[0]);
        int rootIndex = 0;
        while (vin[rootIndex] != root->val) {  // 找到根在中序遍历中的位置  
            rootIndex ++;
        }
        int leftNum = rootIndex;
        root->left = reConstructBinaryTree(vector<int> (pre.begin() + 1, pre.begin() + 1 + leftNum), 
                                            vector<int> (vin.begin(), vin.begin() + leftNum));
        root->right = reConstructBinaryTree(vector<int> (pre.begin() + 1 + leftNum, pre.end()), 
                                            vector<int> (vin.begin() + 1 + leftNum, vin.end()));
        return root;
    }
};

/// 迭代， 栈
