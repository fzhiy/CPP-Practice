
/*
结论：如果x到不了y+1（但能到y），那么从x到y的任一点出发都不可能到达y+1。因为从其中任一点出发的话，相当于从0开始加油，
而如果从x出发到该点则不一定是从0开始加油，可能还有剩余的油。既然不从0开始都到不了y+1，那么从0开始就更不可能到达y+1了
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int remain = 0, res = -1;
        bool flag = false;
        int n = gas.size(), i = 0;
        while (i < n) {
            int cnt = 0, remain = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                remain += (gas[j] - cost[j]);
                if (remain < 0) {
                    break;
                }
                cnt ++;
            }
            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};