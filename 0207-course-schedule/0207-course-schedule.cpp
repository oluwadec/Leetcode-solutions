class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] == 1) return false;
        if (state[node] == 2) return true;  
        state[node] = 1;
        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, graph, state)) {
                return false;
            }
        }       
        state[node] = 2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (const auto& pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            graph[course].push_back(prereq);
        }       
        vector<int> state(numCourses, 0);       
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, graph, state)) {
                return false;
            }
        }
        return true;
    }
};