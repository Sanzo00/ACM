#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
struct ac{
	int v, c, nex;
}edge[maxn<<1];
int n, m;
int head[maxn], cnt;
int dis[maxn], s, e;
int curedge[maxn];
void addedge(int u, int v, int c) {
	edge[cnt] = {v, c, head[u]};
	head[u] = cnt++;
	edge[cnt] = {u, c, head[v]};
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
		for (int i = 0; i <= n; ++i) curedge[i] = head[i];
		while ((d = dfs(s, inf)) > 0) ans += d;
	}
	return ans;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		int MIN = inf, MAX = -1;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < maxn; ++i) {
			head[i] = -1;
		}
		cnt = 0;
		int u, v, c;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &u, &v);
			if (u < MIN) {
				MIN = u;
				s = i;
			}
			if (u > MAX) {
				MAX = u;
				e = i;
			}
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &u, &v, &c);
			addedge(u, v, c);
		}
		printf("%d\n", Dinic());
	}
	return 0;	
}