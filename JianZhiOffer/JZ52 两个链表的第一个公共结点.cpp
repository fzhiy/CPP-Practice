/*** 
 * @Date: 2022-03-18 22:20:18
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-18 22:22:28
 */

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
// O(m+n) / O(1)，
// 思路：假设两个链表长度分别为a, b；两个指针p1, p2同步遍历两个链表，直到遇到共同节点或到末尾；
        // 若遇到共同节点则 直接返回，否则将指向末尾的节点重新指向另一个链表头部，
        // 然后继续遍历，直到遇到共同节点或到末尾； 这样相当于 a+b = b+a。
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *p1 = pHead1, *p2 = pHead2;
        while (p1 != p2) {
            p1 = p1 ? p1->next : pHead2;
            p2 = p2 ? p2->next : pHead1;
        }
        return p1;
    }
};