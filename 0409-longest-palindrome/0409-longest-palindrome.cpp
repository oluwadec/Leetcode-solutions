class Solution {
public:
    int longestPalindrome(string s) {
        int freq[128] = {0};
        for (char c : s) freq[(int)c]++;

        int length = 0;
        bool hasOdd = false;

        for (int f : freq) {
            length += (f / 2) * 2;
            if (f % 2 == 1) hasOdd = true;
        }
        return hasOdd ? length + 1 : length;
    }
};