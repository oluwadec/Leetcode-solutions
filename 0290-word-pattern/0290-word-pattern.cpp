class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string w;
        while (ss >> w) {
            words.push_back(w);
        }
        if (words.size() != pattern.size()) return false;
        unordered_map< char, string> charToWord;
        unordered_map<string, char> wordToChar;
        for (int i =0; i < pattern.size(); ++i) {
            char c = pattern[i];
            const string& word = words[i];
            auto it1 = charToWord.find(c);
            if (it1 != charToWord.end() && it1->second != word) return false;
            auto it2 = wordToChar.find(word);
            if (it2 != wordToChar.end() && it2->second != c) return false;
            charToWord[c] = word;
            wordToChar[word] = c;
        }
        return true;
    }
};