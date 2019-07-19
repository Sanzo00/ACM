#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
const int maxn = 8e2 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;

int head[maxn], cnt;
int s, e;
int curedge[maxn], dis[maxn];
struct ac{
	int v, c, nex;
}edge[maxn << 8];
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
		if (dis[v] != dis[u] + 1 || c == 0) continue;
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
	int n, f, d, t;
	while (cin >> n >> f >> d) {
		memset(head, -1, sizeof(head));
		cnt = 0;
		s = 0, e = f+n+n+d+1;
		string str;
		for (int i = 1; i <= f; ++i) {
			cin >> t;
			addedge(s, i, t);
		}
		for (int i = 1; i <= d; ++i) {
			cin >> t;
			addedge(f+n+n+i, e, t);
		}
		for (int i = 1; i <= n; ++i) {
			cin >> str;
			for (int j = 0; j < f; ++j) {
				if (str[j] == 'N') continue;
				addedge(j+1, f+i, 1);
			}
		}
		for (int i = 1; i <= n; ++i) {
			cin >> str;
			for (int j = 0; j < d; ++j) {
				if (str[j] == 'N') continue;
				addedge(f+n+i, f+n+n+j+1, 1);
			}
		}
		for (int i = 1; i <= n; ++i) addedge(f+i, f+n+i, 1);
		cout << Dinic() << endl;
	}
	return 0;	
}
