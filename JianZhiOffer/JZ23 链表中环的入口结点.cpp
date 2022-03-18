/*** 
 * @Date: 2022-03-18 09:12:55
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-18 09:23:33
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

/**
 * @brief 1） fast 与 slow 最初都指向头节点，fast步长为2，slow步长为1
 *        2）若存在环，则fast 与 slow 一定会在环中相遇（套圈），这时可以将fast 重新指向头节点，
 *          然后 fast 与 slow 的步长都为1，当他们在此相遇即为环的入口处。
 *         （可画图证明，注意找环的过程fast走过的路程是slow的两倍）
 */
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* fast = pHead, *slow = pHead;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {    // 存在环，此时fast比slow多走了一个环的路程
                fast = pHead;
                while (fast != slow) {    // 此时fast与slow的步伐大小相同
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};