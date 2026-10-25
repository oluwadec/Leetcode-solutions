class Solution {
public:
    string intToRoman(int num) {
        vector<int> vals = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> syms = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string roman = "";
        for (int i = 0; i < vals.size(); ++i) {
            while (num >= vals[i]) {
                roman += syms[i];
                num -= vals[i];
            }
        }
        return roman;
    }
};