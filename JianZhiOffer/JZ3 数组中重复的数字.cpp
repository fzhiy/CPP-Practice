/*** 
 * @Date: 2022-03-26 10:49:41
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-26 10:49:41
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int duplicate(vector<int>& numbers) {
        // write code here
        // 哈希表 O(n) / O(n)
        // 直接排序
        int duplication = -1;
        for (int i = 0; i < numbers.size(); i++) {
            int val = numbers[i];    // 取值
            if (i != val) {  // val 与 i 位置不对应
                if (numbers[numbers[i]] == val) {    // 第一个重复值
                    duplication = val;
                    return duplication;
                }
            }
            numbers[i] = numbers[val];
            numbers[val] = val;
        }
        return duplication;
    }
};