/*** 
 * @Date: 2022-03-25 21:52:02
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-25 21:52:03
 */

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
// O(n) / O(1)
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode->right != nullptr) {   // 存在右子树
            TreeLinkNode* p = pNode->right;
            while (p->left != nullptr) {
                p = p->left;
            }
            return p;
        }
        // 没有右子树
        while (pNode->next != nullptr) { // 存在下一个节点
            if (isLeftChild(pNode)) { // 找d的下一个节点(b), i的下一个节点(a)
                // 子树根节点是父节点的左子节点
                return pNode->next;
            }
            pNode = pNode->next;
        }
        return nullptr;
    }
    bool isLeftChild(TreeLinkNode* p) {
        if (p->next != nullptr && p->next->left == p) {
            return true;
        } else {
            return false;
        }
    }
};