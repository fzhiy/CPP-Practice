/*** 
 * @Date: 2022-04-13 21:19:54
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 21:30:33
 */

// 集合， O(logn) / O(logn)
class Solution {
public:
    int getNextNum(int x) {
        int nextNum = 0;
        while (x) {
            int mod = x % 10;
            nextNum += mod * mod;
            x /= 10;
        }
        return nextNum;
    }
    bool isHappy(int n) {
        set<int> st;
        while (n != 1 && st.count(n) == 0) {
            st.insert(n);
            n = getNextNum(n);
        }
        return n == 1;
    }
};

// 快慢指针 O(logn) / O(1)
class Solution {
public:
    int getNextNum(int x) {
        int nextNum = 0;
        while (x) {
            int mod = x % 10;
            nextNum += mod * mod;
            x /= 10;
        }
        return nextNum;
    }
    bool isHappy(int n) {
        int fast = getNextNum(n);
        int slow = n;
        while (fast != 1 && fast != slow) {
            fast = getNextNum(getNextNum(fast));
            slow = getNextNum(slow);
        }
        return fast == 1;
    }
};