/*** 
 * @Date: 2022-03-27 11:00:50
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-27 11:16:31
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        // O(n) / O(n) 的做法就是开一个辅助数组，存储符合题意得结果 （数据说明这种做法效率很高）
        vector<int> res(array.size());
        int i = 0, j = array.size() - 1;   // 用两个指针目的在于一次遍历就能将所有数放入结果栈，最后将偶数部分反转即可。
        for (int& num : array) {
            if (num & 1) {
                res[i++] = num;
            } else {
                res[j--] = num;
            }
        }
        reverse(res.begin() + j + 1, res.end());    // 反转放置在尾部的偶数部分
        return res;
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        // O(n^2) / O(1) 的要求，明显是不需要开额外的数组，实现原地修改数据元素（所以返回结果是array本身）
        // 很容易想到的是 依次找到奇数顺序放置在数组前部，原来位置区间的元素后移
        int index = 0;
        for (int i = 0; i < array.size(); i ++) {
            if (array[i] & 1) { // 是奇数
                int temp = array[i];
                for (int k = i; k > index; k--) {
                    array[k] = array[k - 1];
                }
                array[index++] = temp;
            }
        }
        return array;
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        // O(n^2) / O(1) 的要求，明显是不需要开额外的数组，实现原地修改数据元素（所以返回结果是array本身）
        // 很容易想到的是 依次找到奇数顺序放置在数组前部，原来位置区间的元素后移
        for (int i = 0; i < array.size(); i ++) {
            if (array[i] & 1) { // 是奇数，则不动
                continue;
            }
            bool flag = false;    // 标记位置i之后的位置是否存在奇数(这个标记优点类似冒泡排序优化算法的标记)
            for (int j = i + 1; j < array.size(); j ++) {
                if (array[j] & 1) {
                    int temp = array[j];
                    for (int k = j; k > i; k --) {
                        array[k] = array[k - 1];
                    }
                    array[i] = temp;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        return array;
    }
};