/*** 
 * @Date: 2022-04-12 15:21:34
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-12 15:29:21
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* l1 = list1->val < list2->val ? list1 : list2;
        ListNode* l2 = list1->val < list2->val ? list2 : list1;
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
};

class Solution {
public:
    // 迭代， 新建dummy节点 O(m + n) / O(1)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1 = list1, *p2 = list2;
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p->next = p1 ? p1 : p2;
        return dummy->next;
    }
};