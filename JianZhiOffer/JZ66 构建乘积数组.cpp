/*** 
 * @Date: 2022-03-27 10:39:09
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-27 10:40:11
 */

// O(n) / O(1)
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        // left[i + 1] = left[i] * A[i]
        // right[i] = right[i + 1] * A[i + 1]
        vector<int> B(A.size(), 1);
        for (int i = 1; i < A.size(); i ++) {
            B[i] = B[i - 1] * A[i - 1]; // B[i] 代替left[i]
        }
        int temp = 1;
        for (int i = A.size() - 2; i >= 0; i--) {
            temp *= A[i + 1];    // temp 代替 right[i]
            B[i] *= temp;
        }
        return B;
    }
};