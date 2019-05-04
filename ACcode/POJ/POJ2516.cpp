#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <time.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 100 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;

int path[maxn], dis[maxn], head[maxn];
bool vis[maxn];
int n, m, k, cnt;
struct ac{
	int v, c, cost, pre;
}edge[maxn<<7];
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

int need[maxn][maxn], have[maxn][maxn];
int money[maxn][maxn][maxn];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (scanf("%d%d%d", &n, &m, &k), n) {
	    int s = 0, e = n + m + 1;
    	for (int i = 1; i <= n; ++i) {
    		for (int j = 1; j <= k; ++j) {
	    		scanf("%d", &need[i][j]);
    		}
    	}
    	for (int i = 1; i <= m; ++i) {
    		for (int j = 1; j <= k; ++j) {
	    		scanf("%d", &have[i][j]);
    		}
    	}
    	for (int i = 1; i <= k; ++i) {
    		for (int j = 1; j <= n; ++j) {
    			for (int z = 1; z <= m; ++z) {
    				scanf("%d", &money[i][j][z]);

    			}
    		}
    	}
    	// judge
    	int flag = 0;
    	for (int i = 1; i <= k; ++i) {
    		int sum1 = 0, sum2 = 0;
    		for (int j = 1; j <= n; ++j) sum1 += need[j][i];
    		for (int j = 1; j <= m; ++j) sum2 += have[j][i];
    		if (sum2 < sum1) {
    			flag = 1;
    			break;
    		}
    	}
    	if (flag) {
    		puts("-1");
    		continue;
    	}
    	int ans = 0;
    	for (int i = 1; i <= k; ++i) {
	    	cnt = 0;
    		mem(head, -1);
    		for (int j = 1; j <= m; ++j) {
    			addedge(s, j, have[j][i], 0);
    			addedge(j, s, 0, 0);
    		}
    		for (int j = 1; j <= m; ++j) {
    			for (int z = 1; z <= n; ++z) {
    				addedge(j, z+m, inf, money[i][z][j]);
    				addedge(z+m, j, 0, -money[i][z][j]);
    			}
    		}
    		for (int j = 1; j <= n; ++j) {
    			addedge(j+m, e, need[j][i], 0);
    			addedge(e, j+m, 0, 0);
    		}
    		MincostMaxflow(s, e, ans);
    	}
    	printf("%d\n", ans);
    }
    return 0;
}
