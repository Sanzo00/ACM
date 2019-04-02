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
int n, m;
int dis[maxn], vis[maxn];
int head[maxn], cnt;
struct ac{
    int v, w, pre;
    bool operator < (const ac &t) const{
        if (t.w != w) return t.w > w;
        return t.v < v;
    }
}edge[maxn<<10];
vector<ac> g[maxn];

void add(int u, int v, int w) {
    edge[cnt] = {v, w, head[u]};
    head[u] = cnt++;
}

int Dijkstra(int s, int e) {
    mem(dis, 0);
    mem(vis, 0);
    dis[s] = inf;
    priority_queue<ac> que;
    que.push({s, inf});
    while (!que.empty()) {
        ac f = que.top();
        que.pop();
        if (vis[f.v]) continue;
        vis[f.v] = 1;
        if (f.v == e) break;
        for (int i = 0, v,w; i < (int)g[f.v].size(); ++i) {
            v = g[f.v][i].v;
            w = g[f.v][i].w;
            if (vis[v] || dis[v] >= min(f.w, w)) continue;
            dis[v] = min(f.w ,w);
            que.push({v, dis[v]});
        }
        // for (int i = head[f.v], w,v; i != -1; i = edge[i].pre) {
        //     v = edge[i].v;
        //     w = edge[i].w;
        //     if (vis[v] || dis[v] >= min(f.w, w)) continue;
        //     // if (vis[v] || dis[v] <= f.w + w) continue;
        //     // dis[v] = f.w + w;
        //     dis[v] = min(f.w ,w);
        //     que.push({v, dis[v]});
        // }
    }
    return dis[e];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cout << "Scenario #" << Case++ << ":\n";
        cin >> n >> m; 
        for (int i = 0; i <= n; ++i) g[i].clear();
        // mem(head, -1);
        // cnt = 0;
        for (int i = 0, u,v,w; i < m; ++i) {
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            // add(u, v, w);
            // add(v, u, w);
        }

        int ans = Dijkstra(1, n);
        cout << ans << endl << endl;
    }

    return 0;
}
