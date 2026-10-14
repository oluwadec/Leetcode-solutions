class Solution {
public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string word;
        string result = "";
        string suffix = "a";
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int index = 1;
        while (ss >> word) {
            if (index > 1) {
                result += " ";
            }
            if (vowels.count(word[0])) {
                word += "ma";
            } else {
                char firstChar = word[0];
                word = word.substr(1) + firstChar + "ma";
            }
            word += suffix;
            suffix += "a";
            result += word;
            index++;
        }
        return result;
    }
};