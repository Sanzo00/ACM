#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 1e3 + 7;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
int dis[2][maxn], vis[maxn], tmp[maxn];
vector<P> g[maxn];
int n, s, e, m, k;
int Num(int x) {
	return x == s;
}
void Dijkstra(int x) {
    mem(vis, 0);
    dis[Num(x)][x] = 0;
    for (int i = 1; i <= n; ++i) {
        int MIN = inf, u = -1;
        for (int j = 1; j <= n; ++j) {
            if (vis[j]) continue;
            if (dis[Num(x)][j] < MIN) {
                MIN = dis[Num(x)][j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = 1;
        for (P it : g[u]) {
            int v = it.first;
            int w = it.second;
            if (vis[v]) continue;
            if (dis[Num(x)][v] > MIN + w) {
                dis[Num(x)][v] = MIN + w;
        	}
        }
    }
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> s >> e >> m;
    for (int i = 1, u,v,w; i <= m; ++i) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    mem(dis[Num(s)], inf);
    Dijkstra(s);
    mem(dis[Num(e)], inf);
    Dijkstra(e);

    int ans = dis[Num(s)][e];
    int flag = 0;
    cin >> k;
    for (int i = 1, u,v; i <= k; ++i) {
        cin >> u >> v;
        if (dis[Num(s)][u] + dis[Num(e)][v] < ans) {
        	ans = dis[Num(s)][u] + dis[Num(e)][v];
        	flag = 1;
        }else if (dis[Num(s)][v] + dis[Num(e)][u] < ans) {
        	ans = dis[Num(s)][v] + dis[Num(e)][u];
        	flag = 1;
        }
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";
    cout << ans << "\n";
 
    return 0;
}