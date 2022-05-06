
// 位运算, num & (num - 1)表示去掉 num 的最低位的1.
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 0; i <= n; i ++) {
            int num = i, cnt = 0;
            while (num != 0) {
                ++ cnt;
                num = (num & (num - 1));
            }
            res[i] = cnt;
        }
        return res;
    }
};