class Solution {
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& currentPath, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(currentPath);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            currentPath.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, currentPath, result);
            currentPath.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentPath;
        backtrack(candidates, target, 0, currentPath, result);
        return result;
    }
};