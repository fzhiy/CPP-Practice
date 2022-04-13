/*** 
 * @Date: 2022-04-13 19:49:11
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 19:53:40
 */

// O(m + n) / O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while (p != q) {
            p = p->next;
            q = q->next;
            if (!p && !q) return nullptr;
            if (p == nullptr) p = headB;
            if (q == nullptr) q = headA;
        }
        return p;
    }
};
