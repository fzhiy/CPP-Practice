/*** 
 * @Date: 2022-03-19 14:34:22
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-19 14:41:20
 */
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

// 1) 朴素写法， 先求长度，然后判断 k 与 长度 len的大小关系；然后返回响应结果 O(n) / O(1)
// 2) 双指针法：快指针先走 k 步（可能链表长度不足k），然后快慢指针同时走到末尾 返回慢指针slow （这样节省了求长度的空间 与 部分时间）
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        int len = 0;
        for (ListNode* p = pHead; p; p = p->next) {
            len ++;
        }
        if (k > len || k == 0) return nullptr;
        if (k == len) return pHead;
        k = len - k;
        ListNode* cur = pHead;
        while (k--) {
            cur = cur->next;
        }
        return cur;
    }
};

// 双指针
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        ListNode *fast = pHead, *slow = pHead;
        for (int i = 0; i < k; i ++) {
            if (fast == nullptr) return nullptr;
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};