#include <iostream>
#include <queue>
#include <cstring>
const int maxn = 4e2 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
struct ac{
	int v, c, nex;
}edge[maxn << 4];
int head[maxn], curedge[maxn], cnt, s, e;
int dis[maxn];
void init() {
	memset(head, -1, sizeof(head));
	cnt = 0;
}
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
			if (dis[v] || c == 0) continue;
			dis[v] = dis[u] + 1;
			que.push(v);
		}
	}
	return dis[e] > 0;
}
int dfs(int u, int flow) {
	if (u == e || flow == 0) return flow;
	for (int &i = curedge[u]; i != -1; i = edge[i].nex) {
		int v = edge[i].v;
		int c = edge[i].c;
		if (dis[v] != dis[u] + 1) continue;
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
	int ans = 0, tmp;
	while (bfs()) {
		for (int i = 0; i <= e; ++i) curedge[i] = head[i];
		while ((tmp = dfs(s, inf)) > 0) ans += tmp;
	}
	return ans;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, f, d;
    while (cin >> n >> f >> d) {
    	init();
	    s = 0, e = n*2 + f + d + 1;
	    for (int i = 1; i <= n; ++i) {
	    	int a, b, t;
	    	cin >> a >> b;
	    	for (int j = 1; j <= a; ++j) {
	    		cin >> t;
	    		addedge(t, f+i, 1);
	    	}
	    	for (int j = 1; j <= b; ++j) {
	    		cin >> t;
	    		addedge(f+n+i, n*2+f+t, 1);
	    	}
	    }
	    for (int j = 1; j <= f; ++j) addedge(s, j, 1);
	    for (int j = 1; j <= d; ++j) addedge(n*2+f+j, e, 1);
	    for (int j = 1; j <= n; ++j) addedge(f+j, f+n+j, 1);
	    cout << Dinic() << endl;
    }
    return 0;
}