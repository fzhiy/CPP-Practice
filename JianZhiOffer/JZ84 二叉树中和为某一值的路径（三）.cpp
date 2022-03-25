/*** 
 * @Date: 2022-03-25 21:12:55
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-25 21:27:44
 */

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// O(nlogn) (每个节点都可能作为一条路径的起始点，logn为高度，最差情况是O(n^2)) / O(n), n为二叉树的节点树
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型
     */
    int FindPath(TreeNode* root, int sum) {
        // write code here
        if (!root) return 0;
        int res = 0;
        dfs(root, sum, res);
        res += FindPath(root->left, sum) + FindPath(root->right, sum);
        return res;
    }
    void dfs(TreeNode* root, int sum, int& res) {
        if (sum == root->val) {
            res ++;
            // 这里暂时不能用 return; 因为还可能下面的层级的节点和可能为0，这种情况也是符合题意的路径的
        }
        if (root->left) {
            dfs(root->left, sum - root->val, res);
        }
        if (root->right) {
            dfs(root->right, sum - root->val, res);
        }
    }
};

// O(n) / O(n)。 这里只需要一次遍历所有节点。哈希表存储从根节点到任意子节点的路径和的条数。
// 这里哈希表 很好的将 原问题中的子节点路径和问题 转换成 根节点出发的路径和问题。
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型
     */
    int FindPath(TreeNode* root, int sum) {
        // write code here
        if (!root) return 0;
        mp[0] = 1; // 路径和为0的有1条
        return dfs(root, sum, 0);
    }
    // last： 到上一层为止的累加和
    int dfs(TreeNode* root, int sum, int last) {
        if (!root) return 0;
        int res = 0;
        int temp = root->val + last; // 到当前节点root的累加和
        if (mp.find(temp - sum) != mp.end()) {
            // 如果累加和 temp - sum 在哈希表中出现过，相当于减去前面的分支
            res += mp[temp - sum];  // 加上现有的路径数
        }
        mp[temp]++; // 当前的路径和条数+1
        res += dfs(root->left, sum, temp);
        res += dfs(root->right, sum, temp);
        mp[temp]--;  // 回溯, 别的树枝不经过这条路径
        return res;
    }
private:
    unordered_map<int, int> mp; // 记录路径和及条数
};