/*** 
 * @Date: 2022-03-24 10:26:32
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-24 10:37:52
 */

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// 由于是二叉搜索树，所以中序遍历的结果即是 排序后的结果。
// 递归
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
    int KthNode(TreeNode* proot, int k) {
        // write code here
        if (k == 0 || proot == nullptr) return -1; 
        vector<int> inOrderVec;
        inOrderTravel(proot, inOrderVec);
        return k > inOrderVec.size() ? -1 : inOrderVec[k-1];
    }
    void inOrderTravel(TreeNode* proot, vector<int>& vec) {
        if (!proot) return;
        inOrderTravel(proot->left, vec);
        vec.push_back(proot->val);
        inOrderTravel(proot->right, vec);
    }
};

// 非递归，栈
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
    int KthNode(TreeNode* proot, int k) {
        // write code here
        if (k == 0 || proot == nullptr) return -1; 
        vector<int> inOrderVec;
        stack<TreeNode*> stk;
        TreeNode *p = proot;
        while (!stk.empty() || p != nullptr) {
            if (p != nullptr) {
                stk.push(p);
                p = p->left;
            } else {
                p = stk.top();
                stk.pop();
                inOrderVec.push_back(p->val);
                p = p->right;
            }
        }
        return k > inOrderVec.size() ? -1 : inOrderVec[k-1];
    }
};