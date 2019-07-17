#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int path[maxn], dis[maxn], head[maxn], vis[maxn];
int cnt, s, e;
void init() {
	memset(head, -1, sizeof(head));
	cnt = 0;
}
struct ac{
	int v, c, cost, nex;
}edge[maxn << 11];
void addedge(int u, int v, int c, int cost) {
	edge[cnt] = {v, c, cost, head[u]};
	head[u] = cnt++;
	edge[cnt] = {u, 0, -cost, head[v]};
	head[v] = cnt++;
}
int spfa(int s, int e) {
	memset(vis, 0, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	memset(path, -1, sizeof(path));
	queue<int> que;
	que.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		vis[u] = 0;
		for (int i = head[u]; i != -1; i = edge[i].nex) {
			int v = edge[i].v;
			int c = edge[i].c;
			int cost = edge[i].cost;
			if (dis[v] > dis[u] + cost && c > 0) {
				dis[v] = dis[u] + cost;
				path[v] = i;
				if (vis[v]) continue;
				vis[v] = 1;
				que.push(v);
			}
		}
	}
	return dis[e] != inf;
}
int MincostMaxflow(int s, int e, int &cost) {
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
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m; char c;
	while (cin >> n >> m, n) {
		init();
		vector<pair<int,int> > H, M;
		for(int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> c;
				if (c == 'm') M.push_back(make_pair(i, j));
				if (c == 'H') H.push_back(make_pair(i, j)); 
			}
		}
		int cntH = H.size();
		int cntM = M.size();
		s = 0, e = cntH + cntM + 1;
		for (int i = 0; i < cntM; ++i) {
			addedge(s, i+1, 1, 0);
		}
		for (int i = 0; i < cntH; ++i) {
			addedge(cntM+i+1, e, 1, 0);
		}
		for (int i = 0; i < cntH; ++i) {
			for (int j = 0; j < cntM; ++j) {
				int cost = fabs(H[i].first - M[j].first) + fabs(H[i].second - M[j].second);
				addedge(j+1, cntM+i+1, 1, cost);
			}
		}
		int cost = 0;
		MincostMaxflow(s, e, cost);
		cout << cost << endl;
	}
	return 0;	
}