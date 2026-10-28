class Solution {
    void dfs(vector<int>& c, int t, int i, vector<int>& p, vector<vector<int>>& r) {
        if (t == 0) { r.push_back(p); return; }
        if (t < 0 || i == c.size()) return;
        p.push_back(c[i]);
        dfs(c, t - c[i], i, p, r);
        p.pop_back();
        dfs(c, t, i + 1, p, r);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> r;
        vector<int> p;
        dfs(candidates, target, 0, p, r);
        return r;
    }
};