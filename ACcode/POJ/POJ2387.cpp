#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
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
using namespace std;
const int maxn = 1005;
const int inf = 0x3f3f3f3f;
struct ac{
    int v, w;
    bool operator < (const ac &t) const{
        if (t.w != w) return t.w < w;
        return t.v < v;
    }
};
vector<ac> g[maxn];
int n, m;
int dis[maxn], vis[maxn];
int Dijkstra(int s, int e) {
    mem(dis, inf);
    mem(vis, 0);
    dis[s] = 0;
    priority_queue<ac> que;
    que.push({s, 0});
    while (!que.empty()) {
        ac f = que.top();
        que.pop();
        if (vis[f.v]) continue;
        vis[f.v] = 1;
        if (f.v == e) break;
        for (int i = 0, v,w; i < (int)g[f.v].size(); ++i) {
            v = g[f.v][i].v;
            w = g[f.v][i].w;
            if (vis[v] || dis[v] <= f.w + w) continue;
            dis[v] = f.w + w;
            que.push({v, dis[v]});
        }
    }
    return dis[e];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    cin >> m >> n; 
    for (int i = 0, u,v,w; i < m; ++i) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int ans = Dijkstra(n, 1);
    cout << ans << endl;        

    return 0;
}