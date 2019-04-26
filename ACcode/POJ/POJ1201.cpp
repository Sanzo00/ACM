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
const int maxn = 1e5 + 5;
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
	mem(dis, -inf);
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
			if (dis[x.second] >= dis[f] + x.first) continue;
			dis[x.second] = dis[f] + x.first;
			if (vis[x.second] == 0) {
				vis[x.second] = 1;
				que.push(x.second);
				if (++cnt[x.second] >= e) return -1;
			}
		}
	}
	return dis[e];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, s = 1e9, e = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
    	int a, b, c;
    	scanf("%d%d%d", &a, &b, &c);
    	s = min(a, s);
    	e = max(b+1, e);
    	add(a, b+1, c);
    }
    for (int i = s; i < e; ++i) {
    	add(i, i+1, 0);
    	add(i+1, i, -1);
    }
    int ans = Spfa(s, e);
    printf("%d\n", ans);
    return 0;
}