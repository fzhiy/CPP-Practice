

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& temp, int index) {
        if (index == candidates.size()) {
            return ;
        }
        if (target == 0) {
            res.push_back(temp);
            return ;
        }
        if (target < candidates[index]) {   // candidates有序的前提下进行剪枝
            return ;
        }
        // 跳过当前数
        dfs(candidates, target, res, temp, index + 1);
        // 选择当前数
        if (target >= candidates[index]) {
            temp.push_back(candidates[index]);
            dfs(candidates, target - candidates[index], res, temp, index);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, res, temp, 0);
        return res;
    }
};