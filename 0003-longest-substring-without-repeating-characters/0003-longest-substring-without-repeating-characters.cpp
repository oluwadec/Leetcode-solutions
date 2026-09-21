class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(128, -1); // ASCII Char -> last index seen
        int left = 0;
        int longest = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            if (lastSeen[c] >= left) {
                left = lastSeen[c] +1;
            }
            
            lastSeen[c] = right;
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};