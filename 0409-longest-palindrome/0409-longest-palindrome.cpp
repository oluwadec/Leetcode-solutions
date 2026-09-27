class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        int length = 0;
        bool hasOdd = false;
        for (auto& [ch, cnt] : count) {
            length += (cnt / 2) * 2;
            if (cnt % 2 == 1) hasOdd = true;
        }
        return hasOdd ? length + 1 : length;
    }
};