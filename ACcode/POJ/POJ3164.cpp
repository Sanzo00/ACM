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
const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
struct ac{
	int u, v;
	double w;
};
vector<ac>g(maxn);
int pre[maxn], vis[maxn], id[maxn];
double in[maxn];
double zhuliu(int rt, int n, int m) {
	int u, v;
	double ans = 0, w;
	while (1) {
		for (int i = 0; i < n; ++i) in[i] = inf;
		for (int i = 0; i < m; ++i) {
			u = g[i].u; v = g[i].v; w = g[i].w;
			if (u != v && w < in[v]) {
				pre[v] = u;
				in[v] = w;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (i != rt && in[i] == inf) return -1;
		}
		int cnt = 0;
		mem(id, -1);
		mem(vis, -1);
		in[rt] = 0;
		for (int i = 0; i < n; ++i) {
			ans += in[i];
			u = i;
			while (vis[u] != i && id[u] == -1 && u != rt) {
				vis[u] = i;
				u = pre[u];
			}
			if (u != rt && id[u] == -1) {
				v = pre[u];
				while (v != u) {
					id[v] = cnt;
					v = pre[v];
				}
				id[u] = cnt++;
			}
		}
		if (cnt == 0) break;
		for (int i = 0; i < n; ++i) {
			if (id[i] == -1) id[i] = cnt++;
		}
		for (int i = 0; i < m; ++i) {
			v = g[i].v;
			g[i].u = id[g[i].u];
			g[i].v = id[g[i].v];
			if (g[i].u != g[i].v) g[i].w -= in[v];
		}
		n = cnt;
		rt = id[rt];
	}
	return ans;
}
double Dis(P x, P y) {
	return sqrt((x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
    	vector<P> point(n);
	    for (int i = 0; i < n; ++i) {
	    	scanf("%d%d", &point[i].first, &point[i].second);
	    }
	    int len = 0;
	    for (int i = 0, x,y; i < m; ++i) {
	    	scanf("%d%d", &x, &y);
	    	x--; y--;
	    	g[len].u = x;
	    	g[len].v = y;
	    	g[len++].w = Dis(point[x], point[y]);
	    }
	    double ans = zhuliu(0, n, len);
	    if (ans == -1) puts("poor snoopy");
	    else printf("%.2f\n", ans);
    }
    return 0;
}