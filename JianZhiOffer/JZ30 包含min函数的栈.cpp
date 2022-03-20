/*** 
 * @Date: 2022-03-20 10:56:45
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-20 11:15:40
 */

// O(1) / O(n)（最坏情况下要保存全部值）
class Solution {
public:
    void push(int value) {
        stk.push(value);
        if (minVal.empty()) {
            minVal.push(value);
        } else {
            if (value <= minVal.top()) {
                minVal.push(value);
            } 
//             else {       // 对于 value > minVal.top() 的不需要入栈，在pop时对minVal做处理（平均情况下可以减少minVal栈的消耗）
//                 minVal.push(minVal.top());
//             }
        }
    }
    void pop() {
        if (minVal.top() == stk.top()) {
            minVal.pop();
        }
        stk.pop();
    }
    int top() {
        return stk.top();
    }
    int min() {
        return minVal.top();
    }
private:
    stack<int> stk, minVal;
};

// 残差法，数据栈保存 入栈值与最小栈值的差。 O(1) / O(1)
class Solution {
public:
    void push(int value) {
        if (data.empty()) {
            minData = value;
        }
        data.push(value - minData);    // 数据栈入栈
        if (value - minData < 0) {    // 入栈值小于当前最小值
            minData = value;
        }
    }
    
    void pop() {
        if (data.top() <= 0) {    // 出栈值为最小值
            minData = minData - data.top();
        }
        data.pop();
    }
    int top() {
        if (data.top() <= 0) {
            return minData;
        } else {
            return minData + data.top();    // 返回数据栈栈顶元素
        }
    }
    int min() {
        return minData;
    }
private:
//     stack<int> stk, minVal;
    stack<int> data; // 数据栈（记录每个元素与最小值的差）
    int minData;
};