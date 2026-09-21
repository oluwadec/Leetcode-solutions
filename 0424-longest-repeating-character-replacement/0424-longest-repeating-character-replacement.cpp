class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count (26, 0);
        int left = 0;
        int maxFreq = 0;
        int longest = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            // If window can't be fixed with k replacements, shrink it
            while ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};