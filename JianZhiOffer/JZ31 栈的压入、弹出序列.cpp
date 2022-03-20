/*** 
 * @Date: 2022-03-20 11:21:20
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-20 11:28:41
 */

// O(n) / O(n) 最坏情况下所有元素都会进栈
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> stk;
        int idx = 0;
        for (int i = 0; i < pushV.size(); i++) {
            stk.push(pushV[i]);
            while (!stk.empty() && stk.top() == popV[idx]) {
                idx ++;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

// 使用变量size（利用了vector的下标，O(1)存取的特性） 代替辅助栈 做空间优化（O(n) / O(1)）
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int size = 0;
        int idx = 0;
        for (int i = 0; i < pushV.size(); i++) {
            pushV[size++] = pushV[i];    // 每次更新栈顶数据(顺序遍历使得 [0, i]对应空间可以作为它用了)
            while (size != 0 && pushV[size - 1] == popV[idx]) {
                size --;
                idx ++;
            }
        }
        return size == 0;
    }
};