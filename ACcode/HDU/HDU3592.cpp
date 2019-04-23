#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <iostream>
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
using namespace std;
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
vector<P>g[maxn];
int dis[maxn], vis[maxn], cnt[maxn];
int n, m, k;
struct cmp {
	bool operator()(int x, int y){
		return dis[x] < dis[y];
	}
};
int Spfa(int s) {
	priority_queue<int> que;
	mem(dis, inf);
	mem(vis, 0);
	mem(cnt, 0);
	dis[s] = 0;
	que.push(s);
	cnt[s]++;
	vis[s] = 1;
	while (!que.empty()) {
		int u = que.top();
		que.pop();
		vis[u] = 0;
		int len = g[u].size();
		for (int i = 0; i < len; ++i) {
			int v = g[u][i].second;
			int c = g[u][i].first;
			if (dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				if (!vis[v]) {
					que.push(v);
					vis[v] = 1;
					cnt[v]++;
					if (cnt[v] > n) return -1;
				}
			}
		}
	}
	return dis[n] == inf;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    scanf("%d", &T);
    while (T--) {
    	scanf("%d%d%d", &n, &m, &k);
    	for (int i = 1; i <= n; ++i) g[i].clear();
	 	int u, v, w;
	 	for (int i = 0; i < m; ++i) {
	 		scanf("%d%d%d", &u, &v, &w);
	 		g[u].push_back(make_pair(w, v));
	 	}
	 	for (int i = 0; i < k; ++i) {
	 		scanf("%d%d%d", &u, &v, &w);
	 		g[v].push_back(make_pair(-w, u));
	 	}
	 	int flag = Spfa(1);
	 	if (flag == -1) puts("-1");
	 	if (flag == 1) puts("-2");
	 	if (flag == 0) printf("%d\n", dis[n]);
    }
	 	
    return 0;
}