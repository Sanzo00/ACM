#include <vector>
#include <stdio.h>
#include <iostream>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int ans, num, n, sz[maxn];
vector<int> g[maxn];
void dfs(int u, int fa) {
	sz[u] = 1;
	int mx = 0;
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (v == fa) continue;
		dfs(v, u);
		sz[u] += sz[v];
		mx = max(mx, sz[v]);
	}
	mx = max(mx, n - sz[u]);
	if (mx < ans || (mx == ans && u < num)) {
		ans = mx;
		num = u;
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i <= n; ++i) g[i].clear();
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans = 1e9, num = 1e9;
		dfs(1, 0);
		printf("%d %d\n", num, ans);
	}

	return 0;
}