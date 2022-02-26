class Solution {
public:
	const int inf = 1e6;
	int dp1[13][13];
	int dp2[12][1 << 12];
	int N;

	int shortestPathLength(vector<vector<int>> &graph) {
		N = graph.size();
		int mask = (1 << N) - 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dp1[i][j] = inf;
			}
		}
		for (int u = 0; u < graph.size(); ++u) {
			dp1[u][u] = 0;
			for (int v : graph[u]) {
				dp1[u][v] = dp1[v][u] = 1;
			}
		}
		for (int w = 0; w < N; w++) {
			for (int u = 0; u < N; u++) {
				for (int v = 0; v < N; v++) {
					dp1[u][v] = min(dp1[u][v], dp1[u][w] + dp1[w][v]);
				}
			}
		}
		memset(dp2, -1, sizeof dp2);
		int shortestPath = inf;
		for (int node = 0; node < N; ++node) {
			shortestPath = min(shortestPath, dfs(node, mask ^ (1 << node)));
		}
		return shortestPath;
	}

	int dfs(int u, int mask) {
		if (mask == 0) return 0;
		if (dp2[u][mask] != -1) return dp2[u][mask];
		int ans = inf;
		for (int v = 0; v < N; v++) {
			if (mask & (1 << v)) {
				int len = dfs(v, mask ^ (1 << v)) + dp1[u][v];
				ans = min(ans, len);
			}
		}
		return dp2[u][mask] = ans;
	}
};