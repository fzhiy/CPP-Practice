/*** 
 * @Date: 2022-03-18 22:12:13
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-18 22:16:02
 */
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

// 递归 O(m + n) / O(m + n)
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        
        if (pHead1 == nullptr) return pHead2;
        if (pHead2 == nullptr) return pHead1;
        if (pHead1->val < pHead2->val) {    // pHead1第一个节点元素值较小
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        } else {
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        }
    }
};

// 迭代 O(m + n) / O(1)
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        cur->next = pHead1 ? pHead1 : pHead2;
        return dummy->next;
    }
};