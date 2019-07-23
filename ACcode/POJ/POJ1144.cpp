#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
const int maxn = 1e2 + 5;
using namespace std;

int low[maxn], dfn[maxn], ts, root;
vector<int> g[maxn];
set<int> ans;
void init() {
	ts = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
}
void addedge(int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}
void tarjan(int u) {
	low[u] = dfn[u] = ++ts;
	int len = g[u].size();
	int son = 0;
	for (int i = 0; i < len; ++i) {
		int v = g[u][i];
		if (!dfn[v]) {
			tarjan(v);
			son++;
			low[u] = min(low[u], low[v]);
			if (u == root && son > 1) ans.insert(u);
			else if (u != root && low[v] >= dfn[u]) ans.insert(u);
		}else {
			low[u] = min(low[u], dfn[v]);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	while (scanf("%d", &n), n) {
		for (int i = 0; i <= n; ++i) g[i].clear();
		int u, v;
		while (scanf("%d", &u), u) {
			// 错误读入方式
			// while (scanf("%c", &c) && c != '\n') {
				// if (c == ' ') continue;
				// addedge(u, c - '0');
			// }
			while (getchar() != '\n') {
				scanf("%d", &v);
				addedge(u, v);
			}
		}
		ans.clear();
		init();
		for (int i = 1; i <= n; ++i) {
			root = i;
			if (dfn[i] == 0) tarjan(i);
		}
		printf("%d\n", ans.size());
	}
	return 0;
}