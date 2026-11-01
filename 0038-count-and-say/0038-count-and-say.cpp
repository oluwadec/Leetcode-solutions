class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string current = "1";
        for (int level = 2; level <= n; ++level) {
            string next = "";
            int i = 0;
            int len = current.length(); 
            while (i < len) {
                int count = 1;
                while (i + 1 < len && current[i] == current[i + 1]) {
                    count++;
                    i++;
                }
                next += to_string(count) + current[i];
                i++;
            }
            current = next;
        }
        return current;
    }
};