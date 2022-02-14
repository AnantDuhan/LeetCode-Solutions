class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> inDegree(n, 0);
        vector<vector<int>> graph(n);
        for (auto &v : prerequisites) {
            inDegree[v[0]]++;
            graph[v[1]].emplace_back(v[0]);
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0)
                res.emplace_back(i);
        }

        for (int i = 0; i < res.size(); i++) {
            for (int adj : graph[res[i]]) {
                inDegree[adj]--;
                if (inDegree[adj] == 0)
                    res.emplace_back(adj);
            }
        }

        if (res.size() < n)
            return false;
        return true;
    }
};