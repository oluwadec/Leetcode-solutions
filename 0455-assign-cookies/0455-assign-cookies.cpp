class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;
        int content = 0;

        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                // this cookie satisfies the child
                content++;
                child++;
                cookie++;
            } else {
                // cookie too small, try a bigger one
                cookie++;
            }
        }

        return content;
    }
};