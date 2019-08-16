#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>
#include <vector>
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
vector<int> g[maxn];
int gg[maxn][maxn];
int dfn[maxn], low[maxn], vis[maxn], Stack[maxn], inStack[maxn];
int color[maxn];
int len, cnt, ts;
int n, m;
void init(int n) {
	len = cnt = ts = 0;
	for (int i = 1; i <= n; ++i) g[i].clear();
	fill(vis, vis+n+1, 0);
	fill(dfn, dfn+n+1, 0);
	fill(gg[0], gg[0]+maxn*maxn, 0);
}
int check() {
	fill(color, color+maxn, -1);
	queue<int> que;
	for (int i = 1; i <= n; ++i) {
		if (inStack[i]) {
			que.push(i);
			color[i] = 0;
			break;
		}
	}
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int i = 0; i < (int)g[u].size(); ++i) {
			int v = g[u][i];
			if (inStack[v] == 0) continue;
			if (color[v] == -1) {
				color[v] = color[u] ^ 1;
				que.push(v);
			}else if (color[v] == color[u]) return 1;
		}
	}
	return 0;
}
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++ts;
	Stack[len++] = u;
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (v == fa) continue;
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (dfn[u] <= low[v]) {
				fill(inStack, inStack+n+1, 0);
				inStack[u] = 1; 
				while (1) {
					int top = Stack[--len];
					inStack[top] = 1;
					if (top == v) break;
				}
				if (check()) {
					for (int i = 1; i <= n; ++i) {
						if (inStack[i]) vis[i] = 1;
					}
				}
			}
		}else low[u] = min(low[u], dfn[v]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (scanf("%d %d", &n, &m), n) {
		init(n);
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			gg[u][v] = gg[v][u] = 1;
		}	
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j || gg[i][j]) continue;
				g[i].push_back(j);
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (dfn[i]) continue;
			tarjan(i, 0);
		}
		int ans = n;
		for (int i = 1; i <= n; ++i) ans -= vis[i];
		printf("%d\n", ans);
	}
	return 0;
}