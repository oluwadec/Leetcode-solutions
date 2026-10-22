class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> rowOf;
        string rows[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        for (int i = 0; i < 3; i++) {
            for (char c : rows[i]) {
                rowOf[c] = i;
            }
        }
        vector<string> result;
        for (const string& word : words) {
            bool sameRow = true;
            int targetRow = rowOf[tolower(word[0])];
            for (char c : word) {
                if (rowOf[tolower(c)] != targetRow) {
                    sameRow = false;
                    break;
                }
            }
            if (sameRow) {
                result.push_back(word);
            }
        }
        return result;
    }
};