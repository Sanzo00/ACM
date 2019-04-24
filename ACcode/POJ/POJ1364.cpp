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
const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
vector<P> g[maxn];
int vis[maxn], dis[maxn], cnt[maxn];
void add(int u, int v, int c) {
	g[u].push_back(make_pair(c, v));
}
int Spfa(int s, int e) {
	mem(vis, 0);
	mem(dis, inf);
	mem(cnt, 0);
	dis[s] = 0;
	cnt[s] = 1;
	vis[s] = 1;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		vis[f] = 0;
		int len = g[f].size();
		for (int i = 0; i < len; ++i) {
			P x = g[f][i];
			if (dis[x.second] <= dis[f] + x.first) continue;
			dis[x.second] = dis[f] + x.first;
			if (vis[x.second] == 0) {
				vis[x.second] = 1;
				que.push(x.second);
				if (++cnt[x.second] > e) return -1;
			}
		}
	}
	return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    int a, b, x;
    char t[2];
    while (scanf("%d", &n), n) {
    	scanf("%d", &m);
    	for (int i = 0; i <= 100; ++i) g[i].clear();
    	for (int i = 0; i < m; ++i) {
    		scanf("%d%d%s%d", &a, &b, t, &x);
    		if (t[0] == 'g') add(a+b+1, a, -1-x);
    		else add(a, a+b+1, x-1);
    	}
    	for (int i = 1; i <= n+1; ++i) {
    		add(0, i, 0);
    	}
    	int ans = Spfa(0, n+1);
    	if (ans == -1) puts("successful conspiracy");
    	else puts("lamentable kingdom");
    }

    return 0;
}