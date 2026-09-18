class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == - 1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int, int>> intervals; // valid (start, end) pairs

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] != i) continue; // only expand from a first occurence

            int end = last[c];
            int j = i;
            bool valid = true;
            while (j <= end) {
                int cj = s[j] - 'a';
                if (first[cj] < i) {
                    valid = false;
                    break;
                }
                end = max(end, last[cj]);
                j++;
            }
            if (valid) intervals.push_back({i, end});
        }
        sort(intervals.begin(), intervals.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        vector<string> result;
        int lastEnd = -1;
        for (auto& p : intervals) {
            if (p.first > lastEnd) {
                result.push_back(s.substr(p.first, p.second - p.first + 1));
                lastEnd = p.second;
            }
        }
        return result;
    }
};