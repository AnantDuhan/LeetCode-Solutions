#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
	vector<int> rank, parent, size;
public:
	DisjointSet(int n) {
		rank.resize(n + 1, 0);
		size.resize(n + 1);
		parent.resize(n + 1);

		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	// finding ultimate parent
	int findUltimateParent(int node) {
		if (node == parent[node])
			return node;
		return parent[node] = findUltimateParent(parent[node]);
	}

	void unionByRank(int u, int v) {
		int UltimateParent_u = findUltimateParent(u);
		int UltimateParent_v = findUltimateParent(v);

		if (UltimateParent_u == UltimateParent_v)
			return;

		if (rank[UltimateParent_u] < rank[UltimateParent_v])
			parent[UltimateParent_u] = UltimateParent_v;
		else if (rank[UltimateParent_v] < rank[UltimateParent_u])
			parent[UltimateParent_v] = UltimateParent_u;
		else {
			parent[UltimateParent_v] = UltimateParent_u;
			rank[UltimateParent_u]++;
		}
	}

	void unionBySize(int u, int v) {
		int UltimateParent_u = findUltimateParent(u);
		int UltimateParent_v = findUltimateParent(v);

		if (UltimateParent_u == UltimateParent_v)
			return;

		if (rank[UltimateParent_u] < rank[UltimateParent_v]) {
			parent[UltimateParent_u] = UltimateParent_v;
			size[UltimateParent_v] += size[UltimateParent_u];
		} else {
			parent[UltimateParent_v] = UltimateParent_u;
			size[UltimateParent_u] += size[UltimateParent_v];
		}
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	DisjointSet ds(7);
	ds.unionBySize(1, 2);
	ds.unionBySize(2, 3);
	ds.unionBySize(4, 5);
	ds.unionBySize(6, 7);
	ds.unionBySize(5, 6);
	// check if(3 and 7 belong to same compo or not)
	if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
		cout << "Same\n";
	else
		cout << "Not Same\n";

	ds.unionBySize(3, 7);
	// check if(3 and 7 belong to same compo or not)
	if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
		cout << "Same\n";
	else
		cout << "Not Same\n";
	return 0;
}