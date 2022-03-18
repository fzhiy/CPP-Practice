/*** 
 * @Date: 2022-03-18 09:27:19
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-18 09:29:34
 */

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

/**
 * @brief   1）递归；
 *          2）先遍历填充到数组，然后反转数组
 * 
 */
// 1）递归； O(n) / O(n)
class Solution {
public:
    void dfs(vector<int>& res, ListNode* head) {
        if (head == nullptr) return ;
        dfs(res, head->next);
        res.push_back(head->val);
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        dfs(res, head);
        return res;
    }
};

// 2）先遍历填充到数组，然后反转数组  O(n) / O(n)
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        for (ListNode* p = head; p != nullptr; p = p->next) {
            res.push_back(p->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};