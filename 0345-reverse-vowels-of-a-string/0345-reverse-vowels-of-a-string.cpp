class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [](char c) {
            switch (c) {
                case 'a': case 'e': case 'i': case 'o': case 'u':
                case 'A': case 'E': case 'I': case 'O': case 'U':
                    return true;
                default:
                    return false;
            }
        };

        int left = 0, right = (int)s.size() - 1;

        while (left < right) {
            while (left < right && !isVowel(s[left])) left++;
            while (left < right && !isVowel(s[right])) right--;
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};