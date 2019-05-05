#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 3e2 + 1;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int path[maxn], dis[maxn], head[maxn];
bool vis[maxn];
int n, m, k, cnt;
struct ac{
	int v, c, cost, pre;
}edge[maxn*32];
void addedge(int u, int v, int c, int cost) {
	edge[cnt].v = v;
	edge[cnt].c = c;
	edge[cnt].cost = cost;
	edge[cnt].pre = head[u];
	head[u] = cnt++;
}
bool spfa (int s, int e) {
	mem(vis, false);
	mem(dis, inf);
	mem(path, -1);
	queue<int> que;
	que.push(s);
	dis[s] = 0;
	vis[s] = true;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		vis[u] = false;
		for (int i = head[u]; i != -1; i = edge[i].pre) {
			int v = edge[i].v;
			int c = edge[i].c;
			int cost = edge[i].cost;
			if (dis[v] > dis[u] + cost && c > 0) {
				dis[v] = dis[u] + cost;
				path[v] = i;
				if (!vis[v]) {
					vis[v] = true;
					que.push(v);
				}
			}
		}
	}
	if (dis[e] == inf) return false;
	else return true;
}

int MincostMaxflow(int s, int e, int &cost) {
	int maxflow = 0;
	int flow = inf;
	while (spfa(s, e)) {
		for (int i = path[e]; i != -1; i = path[edge[i^1].v])
			flow = min(flow, edge[i].c);
		for (int i = path[e]; i != -1; i = path[edge[i^1].v]) {
			edge[i].c -= flow;
			edge[i^1].c += flow;
			cost += flow * edge[i].cost;
		}
		maxflow += flow;
	}
	return maxflow;
}

struct ac2{
	int x, y, start, stop;
	int num[7];
}a[maxn];
int Dis(int x, int y, int s, int e) {
	return abs(x - s) + abs(y - e);
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m, k;
    int sx, sy;
    scanf("%d%d%d%d%d", &n, &m, &k, &sx, &sy);
    for (int i = 1; i < n; ++i) {
    	scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].start, &a[i].stop);
    	for (int j = 1; j <= m; ++j) {
    		scanf("%d", &a[i].num[j]);
    	}
    }
    // judge
    for (int i = 1; i < n; ++i) {
    	if (Dis(sx, sy, a[i].x, a[i].y) > a[i].start) k--;
    }
    if (k < 0) {
    	puts("THE END IS COMING!!!!!");
    	return 0;
    }
    n--;
    int s = 0, e = 2 * n + 1;
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
    	mem(head, -1);
    	cnt = 0;
    	for (int j = 1; j <= n; ++j) {
    		if (Dis(sx, sy, a[j].x, a[j].y) > a[j].start) continue;
    		// accept
    		addedge(s, j, a[j].num[i], 1);
    		addedge(j, s, 0, -1);
    		// tot
    		addedge(j, e, a[j].num[i], 0);
    		addedge(e, j, 0, 0);
    		// send
    		addedge(s, n+j, a[j].num[i], 0);
    		addedge(n+j, s, 0, 0);
    		for (int k = 1; k <= n; ++k) {
    			if (k == j) continue;
    			if (Dis(a[j].x, a[j].y, a[k].x, a[k].y) + a[j].stop + a[j].start <= a[k].start) {
    				addedge(j+n, k, inf, 0);
    				addedge(k, j+n, 0, 0);
    			}
    		}
    	}
    	MincostMaxflow(s, e, ans);
    }
    printf("%d\n", ans);

    return 0;
}
