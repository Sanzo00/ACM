#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int head[maxn], now;
struct ac{
	int v, nex;
}edge[maxn<<2];
void add (int u, int v) {
	edge[now].v = v;
	edge[now].nex = head[u];
	head[u] = now++;
}
int low[maxn], dfn[maxn], vis[maxn], pre[maxn], cnt, ts;
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++ts;
	for (int i = head[u]; ~i; i = edge[i].nex) {
		int v = edge[i].v;
		if (fa == v) continue;
		if (!dfn[v]) {
			pre[v] = u;
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u]) {
				cnt++;
				vis[v] = 1;
			}
		}else low[u] = min(low[u], dfn[v]);
	}
}
void lca(int u, int v) {
	if (dfn[u] < dfn[v]) swap(u, v);
	while (dfn[u] > dfn[v]) {
		if (vis[u]) {
			cnt--;
			vis[u] = 0;
		}
		u = pre[u];
	}
	while (dfn[u] < dfn[v]) {
		if (vis[v]) {
			cnt--;
			vis[v] = 0;
		}
		v = pre[v];
	}
}
int main() {
	int n, m, kase = 1;
	while (scanf("%d%d", &n, &m), n+m) {
		printf("Case %d:\n", kase++);
		ts = cnt = now = 0;
		int u, v;
		fill(vis, vis+n+1, 0);
		fill(dfn, dfn+n+1, 0);
		fill(head,head+n+1, -1);
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &u, &v);
			add(u, v);
			add(v, u);
		}
		pre[1] = 1;
		tarjan(1, 0);
		int q;
		scanf("%d", &q);
		while (q--) {
			scanf("%d %d", &u, &v);
			lca(u, v);
			printf("%d\n", cnt);
		}
		puts("");
	}
	return 0;
}