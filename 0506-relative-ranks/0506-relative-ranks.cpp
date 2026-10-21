class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return score[a] > score[b];
        });
        vector<string> answer(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                answer[indices[i]] = "Gold Medal";
            } else if (i == 1) {
                answer[indices[i]] = "Silver Medal";
            } else if (i == 2) {
                answer[indices[i]] = "Bronze Medal";
            } else {
                answer[indices[i]] = to_string(i + 1);
            }
        }
        return answer;
    }
};