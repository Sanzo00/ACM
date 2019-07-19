#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
struct ac{
	int v, c, nex;
}edge[maxn<<5];
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
	while (cin >> n >> m, n&&m) {
		memset(head, -1, sizeof(head));
		cnt = 0;
		s = 1, e = 2;
		vector<pair<int,int> > edges(m);
		for (int i = 0; i < m; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			edges[i] = make_pair(u, v);
			addedge(u, v, c);
			addedge(v, u, c);
		}
		Dinic();	
		for (auto it : edges) {
			int u = it.first;
			int v = it.second;
			if ((dis[u] && !dis[v]) || (!dis[u] && dis[v])) {
				cout << u << " " << v << endl;
			}
		}
		cout << endl;
	}

	return 0;	
}
