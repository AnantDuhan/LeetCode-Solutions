class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n < 2) {
            vector<int> centroids;
            for (int i = 0; i < n; i++)
                centroids.push_back(i);
            return centroids;
        }

        // build the graph;
        unordered_map<int, unordered_set<int>> g;
        for (int i = 0; i < n; i++) {
            g[i] = unordered_set<int>();
        }
        for (auto e : edges) {
            int start = e[0], end = e[1];
            g[start].emplace(end);
            g[end].emplace(start);
        }

        // Initialize then first layer of leaves
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (g[i].size() == 1) leaves.push_back(i);
        }

        // Trim the leaves until reaching the centroids
        int remainingNodes = n;
        while (remainingNodes > 2) {
            remainingNodes -= leaves.size();
            vector<int> newLeaves;

            // remove the current leaves along with the edges
            for (int i : leaves) {
                unordered_set<int> allNeighbors = g[i];
                for (auto n : allNeighbors) {
                    g[n].erase(i);
                    if (g[n].size() == 1)
                        newLeaves.push_back(n);
                }
            }

            leaves = newLeaves;
        }

        // The remaining nodes are the centroids of the graph
        return leaves;
    }
};