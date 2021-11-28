class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int node, int &LastNode, vector<vector<int>> &graph) {
        path.push_back(node);

        if (node == LastNode)
            res.push_back(path);

        for (int i = 0; i < graph[node].size(); i++)
            dfs(graph[node][i], LastNode, graph);

        path.pop_back();

    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        dfs(NULL, --n, graph);
        return res;
    }
};