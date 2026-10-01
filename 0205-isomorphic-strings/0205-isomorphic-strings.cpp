class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int mapST[256] = {0};
        int mapTS[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            unsigned char a = s[i], b = t[i];
              if (mapST[a] != mapTS[b]) return false;

            mapST[a] = mapTS[b] = i + 1;
        }
        return true;
    }
};