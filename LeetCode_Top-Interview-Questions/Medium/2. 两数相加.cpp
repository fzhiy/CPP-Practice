/*** 
 * @Date: 2022-04-13 21:49:26
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 22:02:15
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        int carry = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (p1 || p2) {
            int sum = carry;
            if (p1) {
                sum += p1->val;
                p1 = p1->next;
            } 
            if (p2) {
                sum += p2->val;
                p2 = p2->next;
            }
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            carry = sum / 10;
        }
        if (carry) {
            cur->next = new ListNode(carry);
            cur = cur->next;
        }
        cur->next = nullptr;
        return dummy->next;
    }
};