#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
const int maxn = 3e2 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
struct ac{
	int v, c, nex;
}edge[maxn<<9];
int head[maxn], cnt;
int dis[maxn], s, e;
int curedge[maxn];
int n, m, f;
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
int pre[maxn];
int find(int x) {
	return (x == pre[x]) ? x : pre[x] = find(pre[x]);
}
void join(int x, int y) {
	if (x == y) return;
	if (x > y) swap(x, y);
	pre[y] = x;
	return;  
}
vector<int> g[maxn];
int vis[maxn];
int check(int x) {
	memset(head, -1, sizeof(head));
	cnt = 0;
	for (int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof(vis));
		for (int j = 0; j < (int)g[i].size(); ++j) {
			int u = g[i][j];
			if (vis[u]) continue;
			// 找girl u的朋友
			for (int k = 1; k <= n; ++k) {
				if (vis[k] || find(u) != find(k)) continue;
				addedge(k, i+n, 1);
				vis[k] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) addedge(s, i, x), addedge(i+n, e, x);
	return Dinic() == x*n;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> f;
		s = 0, e = n * 2 + 1;
		for (int i = 0; i <= n; ++i) g[i].clear();
		for (int i = 0; i <= n; ++i) pre[i] = i;
		
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			g[v].push_back(u);
		}
		for (int i = 0; i < f; ++i) {
			int u, v;
			cin >> u >> v;
			join(find(u), find(v));
		}
		int l = 0, r = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) l = mid + 1;
			else r = mid - 1;
		}
		cout << r << endl;
	}
	return 0;	
}