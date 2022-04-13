/*** 
 * @Date: 2022-04-13 21:39:51
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-13 21:46:21
 */

// 残差法，用一个变量存储最小值，
// 数据栈 保存 元素与最小值的差值 O(1) / O(1)
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        if (data.empty()) {
            minData = val;
        }
        data.push((long)val - minData);   // 数据栈 入栈
        if ((long)val - minData < 0) {    // 入栈值 小于 当前最小值
            minData = val;
        }
    }
    
    void pop() {
        if (data.top() <= 0) { // 出栈值位最小值
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
    
    int getMin() {
        return minData;
    }   
private:
    long minData;
    stack<long> data;    //数据栈，记录每个元素与最小值的差（残差法）
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */