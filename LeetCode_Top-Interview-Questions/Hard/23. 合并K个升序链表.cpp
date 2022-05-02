/*** 
 * @Date: 2022-05-01 17:32:09
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-05-01 17:33:11
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
// 优先队列 O(nk logk) / O(k). k表示有k条链表，每条链表n个元素
class Solution {
public:
    struct Status {
        int val;
        ListNode* ptr;
        bool operator < (const Status& rhs) const {
            return val > rhs.val;
        }
    };
    priority_queue<Status> pq;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) pq.push({node->val, node});
        }
        ListNode *dummy = new ListNode(-1);
        ListNode* p = dummy;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            p->next = cur.ptr;
            p = p->next;
            if (cur.ptr->next) {
                pq.push({cur.ptr->next->val, cur.ptr->next});
            }
        }
        return dummy->next;
    }
};