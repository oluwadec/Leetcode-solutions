class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        int required = need.size();   // number of DISTINCT chars we must satisfy
        int formed = 0;                // how many distinct chars currently satisfied

        unordered_map<char, int> window;
        int left = 0;
        int bestLen = INT_MAX;
        int bestLeft = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            window[c]++;

            // If this char is needed and we've just hit the required count, mark satisfied
            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            // Try to shrink the window while it's still fully valid
            while (formed == required) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestLeft = left;
                }

                char leftChar = s[left];
                window[leftChar]--;
                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    formed--;
                }
                left++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestLeft, bestLen);
    }
};