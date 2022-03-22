/*** 
 * @Date: 2022-03-22 10:14:09
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-22 10:21:18
 */

// O(nlogn) / O(1)
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        sort(numbers.begin(), numbers.end());
        int num = 0, n = numbers.size();
        if (numbers[n-1] == 0) return true;
        int i = 0;
        while (numbers[i] == 0) num ++, i++;
        int dis = 0;    // 记录5张牌中最大值与最小值的距离
        while (i < n - 1) {
            if (numbers[i] == numbers[i + 1]) return false;
            dis += numbers[i + 1] - numbers[i] - 1; // 计算距离
            i ++;
        }
        return num >= dis;
    }
};

// O(n) / O(1)，利用位或 实现类似bitmap的功能
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int maxx = 0, minx = 14;
        int flag = 0;
        for (int& num : numbers) {
            if (num == 0) continue;
            maxx = max(maxx, num);
            minx = min(minx, num);
            if ((flag & (1 << num)) != 0) { // 出现重复牌
                return false;
            }
            flag |= (1 << num);     // 标志num出现
        }
        return maxx - minx < 5;
    }
};