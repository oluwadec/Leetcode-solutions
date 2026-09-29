class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        for (char c : t) {
            need[c]++;
        }
        int missing = t.size();
        int left = 0;
        int start = 0;
        int minLen = INT_MAX;
        for (int right = 0; right < s.size(); right++) {
            if (need[s[right]] > 0) {
                missing--;
            }
            need[s[right]]--;
            while (missing == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                need[s[left]]++;
                if (need[s[left]] > 0) {
                    missing++;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start,minLen);
    }
};