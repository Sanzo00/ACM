#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
const int maxn = 2e2 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
struct ac{
	int v, c, nex;
}edge[maxn << 8];
int head[maxn], cnt;
int dis[maxn], s, e;
int curedge[maxn];
void addedge(int u, int v, int c) {
	edge[cnt] = {v, c, head[u]};
	head[u] = cnt++;
	edge[cnt] = {u, 0, head[v]};
	head[v] = cnt++;
}
int bfs() {
	memset(dis, 0, sizeof(dis));
	dis[s] = 1;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int i = head[u]; i != -1; i = edge[i].nex) {
			int v = edge[i].v;
			int c = edge[i].c;
			if (c == 0 || dis[v]) continue;
			dis[v] = dis[u] + 1;
			que.push(v);
		}
	}
	return dis[e];
}
int dfs(int u, int flow) {
	if (u == e || flow == 0) return flow;
	for (int &i = curedge[u]; i != -1; i = edge[i].nex) {
		int v = edge[i].v;
		int c = edge[i].c;
		if (c == 0 || dis[v] != dis[u] + 1) continue;
		int tmp = dfs(v, min(flow, c));
		if (tmp > 0) {
			edge[i].c -= tmp;
			edge[i^1].c += tmp;
			return tmp;
		}
	}
	dis[u] = -1;
	return 0;
}
int Dinic() {
	int ans = 0, d;
	while (bfs()) {
		for (int i = 0; i <= e; ++i) curedge[i] = head[i];
		while ((d = dfs(s, inf)) > 0) ans += d;
	}
	return ans;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, np, nc, m;
	while (scanf("%d %d %d %d", &n, &np, &nc, &m) != EOF) {
		s = n, e = n + 1;
		memset(head, -1, sizeof(head));
		cnt = 0;
		int u, v, c;
		for (int i = 0; i < m; ++i) {
			scanf(" (%d,%d)%d", &u, &v, &c);
			addedge(u, v, c);
		}
		for (int i = 0; i < np; ++i) {
			scanf(" (%d)%d", &v, &c);
			addedge(s, v, c);
		}
		for (int i = 0; i < nc; ++i) {
			scanf(" (%d)%d", &v, &c);
			addedge(v, e, c);
		}
		printf("%d\n", Dinic());
	}
	return 0;	
}