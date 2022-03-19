/*** 
 * @Date: 2022-03-19 14:48:16
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-19 14:48:16
 */

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
// O(n) / O(1)，只需要额外的两个个指针(dummy, cur)即可
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = pHead;
        ListNode *cur = dummy;
        while (cur->next && cur->next->next) {
            int val = cur->next->val;
            if (val == cur->next->next->val) {
                while (cur->next && cur->next->val == val) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};