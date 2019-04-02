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
using namespace std;

const int maxn = 1001;
const int inf = 0x3f3f3f3f;
int n, m;
int dis[maxn], dis1[maxn], vis[maxn];
int head[maxn], cnt, cnt1, head1[maxn];
struct ac{
    int v, w, pre;
    bool operator < (const ac &t) const{
        if (t.w != w) return t.w < w;
        return t.v < v;
    }
}edge[maxn*100], edge1[maxn*100];
vector<ac> g[maxn];

void add(int u, int v, int w, int t) {
    if (t == 0)
        edge[cnt] = {v, w, head[u]}, head[u] = cnt++;
    else 
        edge1[cnt1] = {v, w, head1[u]}, head1[u] = cnt1++;
}

int Dijkstra(int s, int e, int t) {
    if (t == 0) mem(dis, inf);
    else mem(dis1, inf);
    mem(vis, 0);
    if (t == 0) dis[s] = 0;
    else dis1[s] = 0;
    priority_queue<ac> que;
    que.push({s, 0});
    while (!que.empty()) {
        ac f = que.top();
        que.pop();
        if (vis[f.v]) continue;
        vis[f.v] = 1;
        // if (f.v == e) break;
        // for (int i = 0, v,w; i < (int)g[f.v].size(); ++i) {
        //     v = g[f.v][i].v;
        //     w = g[f.v][i].w;
        //     if (vis[v] || dis[v] <= f.w + w) continue;
        //     dis[v] = f.w + w;
        //     que.push({v, dis[v]});
        // }
        if (t == 0)
            for (int i = head[f.v], w,v; i != -1; i = edge[i].pre) {
                v = edge[i].v;
                w = edge[i].w;
                if (vis[v] || dis[v] <= f.w + w) continue;
                dis[v] = f.w + w;
                que.push({v, dis[v]});
            }
        else 
            for (int i = head1[f.v], w,v; i != -1; i = edge1[i].pre) {
                v = edge1[i].v;
                w = edge1[i].w;
                if (vis[v] || dis1[v] <= f.w + w) continue;
                dis1[v] = f.w + w;
                que.push({v, dis1[v]});
            }
    }
    return dis[e];
}
int tmp[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    int x;
    cin >> n >> m >> x;
    cnt = 0;
    mem(head, -1);
    mem(head1, -1);
    for (int i = 0, u,v,w; i < m; ++i) {
        cin >> u >> v >> w;
        add(u, v, w, 0);
        add(v, u, w, 1);
    }
    int ans = 0;
    Dijkstra(x, x, 0);
    Dijkstra(x, x, 1);
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dis[i] + dis1[i]);
    }
    cout << ans << endl;

    return 0;
}
