/*** 
 * @Date: 2022-03-26 10:48:48
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-26 10:48:49
 */

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0, right = rotateArray.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (rotateArray[right] == rotateArray[mid]) {
                right = right - 1;    // 
            } else if (rotateArray[right] > rotateArray[mid]) {
                right = mid;    // 中间值更接近最小值 (可能是最小值)
            } else {    
                left = mid + 1;    // 最小值在mid位置的后面
            }
        }
        return rotateArray[left];
    }
};