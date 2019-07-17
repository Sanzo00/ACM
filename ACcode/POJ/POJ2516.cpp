#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
struct ac{
	int v, c, cost, nex;
}edge[maxn << 5];
int dis[maxn], vis[maxn];
int head[maxn], cnt, path[maxn];
void addedge(int u, int v, int c, int cost) {
	edge[cnt] = {v, c, cost, head[u]};
	head[u] = cnt++;
	edge[cnt] = {u, 0, -cost, head[v]};
	head[v] = cnt++;	
}
void init() {
	memset(head, -1, sizeof(head));
	cnt = 0;
}
int spfa(int s, int e) {
	memset(vis, 0, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	memset(path, -1, sizeof(path));
	dis[s] = 0;
	vis[s] = 1;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		vis[u] = 0;
		for (int i = head[u]; i != -1; i = edge[i].nex) {
			int v = edge[i].v;
			int c = edge[i].c;
			int cost = edge[i].cost;
			if (c == 0 || dis[v] <= dis[u] + cost) continue;
			path[v] = i;
			dis[v] = dis[u] + cost;
			if (vis[v]) continue;
			vis[v] = 1;
			que.push(v);
		}
	}
	return dis[e] != inf;
}
int MCMF(int s, int e, int &cost) {
	int maxflow = 0;
	while (spfa(s, e)) {
		int flow = inf;
		for (int i = path[e]; i != -1; i = path[edge[i^1].v]) {
			flow = min(flow, edge[i].c);
		}
		for (int i = path[e]; i != -1; i = path[edge[i^1].v]) {
			edge[i].c -= flow;
			edge[i^1].c += flow;
			cost += flow * edge[i].cost;
		}
		maxflow += flow;
	}
	return maxflow;
}
int supply[55][55];
int need[55][55];
int price[55][55][55];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	while (cin >> n >> m >> k, n) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= k; ++j) {
				cin >> need[i][j]; // 商店i需要货物j
			}
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= k; ++j) {
				cin >> supply[i][j]; // 供应商i提供货物j
			}
		}
		for (int q = 1; q <= k; ++q) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					cin >> price[q][j][i]; // 货物q从j到i的价格
				}
			}
		}
		// 分开对每个货物求费用流
		int s = 0, e = m + n + 1;
		int ans = 0;
		for (int q = 1; q <= k; ++q) {
			int sum = 0;
			for (int i = 1; i <= n; ++i) {
				sum += need[i][q];
			}
			init();
			for (int i = 1; i <= m; ++i) addedge(s, i, supply[i][q], 0);
			for (int i = 1; i <= n; ++i) addedge(m+i, e, need[i][q], 0);
			for (int i = 1; i <= m; ++i) {
				for (int j = 1; j <= n; ++j) {
					addedge(i, m+j, inf, price[q][i][j]);
				}
			}
			int maxflow = MCMF(s, e, ans);
			if (maxflow != sum) {
				ans = -1;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}