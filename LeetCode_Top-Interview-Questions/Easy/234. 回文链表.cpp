/*** 
 * @Date: 2022-04-13 21:03:47
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 21:15:35
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
// O(n) / O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* l2 = reverseList(slow->next); // 反转后半部分链表
        ListNode* l2_back = l2;
        slow->next = nullptr;
        fast = head;
        while (l2 && fast) {
            if (l2->val != fast->val) {
                return false;
            }
            l2 = l2->next;
            fast = fast->next;
        }
        reverseList(l2_back);
        slow->next = l2_back;   // 还原链表
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *cur = head, *next;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};