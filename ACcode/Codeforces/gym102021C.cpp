#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 1000 + 5;
using namespace std;

struct ac{
    int v, w;
};
int dis[maxn];
vector<ac> g[maxn];
int dfs(int x) {
    if (dis[x] != -1) return dis[x];
    int d = 0;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        ac y = g[x][i];
        d = max(d, dfs(y.v) + y.w);
    }
    dis[x] = d;
    return dis[x];
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0, u,v,w; i < m; ++i) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    mem(dis, -1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(dfs(i), ans);
    cout << ans << endl;
    return 0;
}
