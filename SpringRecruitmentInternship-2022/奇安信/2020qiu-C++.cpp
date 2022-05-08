
// [编程题]老板发奖金
// 爬楼梯系列问题
class Solution {
public:
    /**
     * 
     * @param num_money int整型 奖金的总数,单位为元
     * @return int整型
     */
    int CalulateMethodCount(int num_money) {
        // write code here
        vector<int> f(11, 0);
        f[0] = 1, f[1] = 1, f[2] = 2;
        for (int i = 3; i < 11; i ++) {
            f[i] = f[i - 1] + f[i - 2] + f[i - 3];
        }
        return f[num_money];
    }
};


// [编程题]撤销与恢复
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> text, undo;
    string s;
    while (cin >> s) {
        if (s == "undo") {
            if (!text.empty()) {
                undo.push_back(text.back());
                text.pop_back();
            }
        } else if (s == "redo") {
            if (!undo.empty()) {
                text.push_back(undo.back());
                undo.pop_back();
            }
        } else {    // 普通单词
            text.push_back(s);
            undo = vector<string>();    //  清空
        }
    }
    for (int i = 0; i < text.size(); i ++) {
        cout << text[i] << " ";
    }
    return 0;
}