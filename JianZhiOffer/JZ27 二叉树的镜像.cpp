/*** 
 * @Date: 2022-03-24 12:26:19
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-24 15:35:37
 */
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// 后序遍历
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if (!pRoot) return nullptr;
        TreeNode* left = Mirror(pRoot->left);
        TreeNode* right = Mirror(pRoot->right);
        pRoot->left = right;
        pRoot->right = left;
        return pRoot;
    }
};

// 中序遍历
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if (!pRoot) return nullptr;
        Mirror(pRoot->left);
        // 交换左右子节点
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        
        Mirror(pRoot->left);   // 前面交换过了所以这里是pRoot->left 而不是 pRoot->right
        
        return pRoot;
    }
};

// 前序遍历
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if (!pRoot) return nullptr;
        // 交换左右子节点
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        
        Mirror(pRoot->right);  // 前面交换过了所以这里是pRoot->right 而不是 pRoot->left
        Mirror(pRoot->left);   // 前面交换过了所以这里是pRoot->left 而不是 pRoot->right
        
        return pRoot;
    }
};

// 非递归，栈， O(n) / O(n)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if (!pRoot) return nullptr;
        stack<TreeNode*> stk;
        stk.push(pRoot);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);
            // 左右子树交换
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
        return pRoot;
    }
};