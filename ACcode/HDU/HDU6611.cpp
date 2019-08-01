#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 5e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int preE[maxn], preV[maxn], dis[maxn], h[maxn];
struct ac{
    int v, c, cost, nex;
};
vector<ac> g[maxn];
void init() {
    for (int i = 0; i < maxn; ++i) g[i].clear();
}
void addedge(int u, int v, int c, int cost) {
	g[u].push_back({v, c, cost, (int)g[v].size()});
	g[v].push_back({u, 0, -cost, (int)g[u].size()-1});
}
int Dijkstra(int s, int e) {
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >que;
	que.push(pair<int,int>(0, s));
	memset(dis, inf, sizeof(dis));
	dis[s] = 0;
	while (!que.empty()) {
		pair<int, int> top = que.top();
		que.pop();
		int u = top.second;
		if (dis[u] < top.first) continue;
		for (int i = 0; i < (int)g[u].size(); ++i) {
			int v = g[u][i].v;
			int cost = g[u][i].cost;
			int c = g[u][i].c;
			if (c > 0 && dis[v] > dis[u] + cost + h[u] - h[v]) {
				dis[v] = dis[u] + cost + h[u] - h[v];
				preE[v] = i;
				preV[v] = u;
				que.push(pair<int,int>(dis[v], v));
			}
		}
	}
	return dis[e] != inf;
}
int MincostMaxflow(int s, int e, int &cost) {
    int maxflow = 0;
    memset(h, 0, sizeof(h));
    while (Dijkstra(s, e)) { 
        for (int i = 0; i <= e; ++i) h[i] += dis[i];
        int flow = inf; 
    	for (int i = e; i != s; i = preV[i]) {
            flow = min(flow, g[preV[i]][preE[i]].c);
        }
        for (int i = e; i != s; i = preV[i]) {
        	ac& t = g[preV[i]][preE[i]]; 
        	t.c -= flow;
        	g[i][t.nex].c += flow;
        }
        cost += flow * h[e];
        maxflow += flow;
    }
    return maxflow;
}
int val[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &val[i]);
        }
        int s = 0, e = 2*n + 2;
        addedge(s, 2*n+1, k, 0);
        for (int i = 1; i <= n; ++i) {
            addedge(2*n+1, i, 1, 0);
            addedge(i, i+n, 1, -val[i]);
            addedge(i+n, e, 1, 0);
            for (int j = i+1; j <= n; ++j) {
                if (val[j] >= val[i]) {
                    addedge(i+n, j, 1, 0);
                }
            }
        }
        int cost = 0;
        MincostMaxflow(s, e, cost);
        printf("%d\n", -cost);
    }
    return 0;
}