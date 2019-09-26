## CF-567F(President and Roads)



[题目链接](https://codeforces.com/contest/567/problem/E)

#### 题意

$S->E$的$DAG$中求:

1. $DAG$中必经边输出"$YES$"

2. $DAG$中非必经边求这条边最少降低多少可以使这条边变成必经边

#### 思路

判断必经边可以用方案数判断,对于一条边$\{u,v\}$,如果$way[u] * rway[v] == way[E]$则该边为必经边.

这题$mod$ = 1e9+7会被卡...

$mod$ = 258280327, 1610612741可以用,或者取两次模



```cpp
#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const long long inf = 1e18;
const int mod = 258280327;
using namespace std;
struct ac{
    long long v, c, id;
    bool operator < (const ac &t) const{
        return t.c < c;
    }
};
vector<ac> g[maxn], rg[maxn]; 
long long dis[maxn], rdis[maxn], vis[maxn], way[maxn], rway[maxn], ans[maxn];
void Dijkstra(int s, int e, long long* dis, long long* way, vector<ac> *edge) {
    fill(dis, dis+maxn, inf);
    fill(vis, vis+maxn, 0);
    dis[s] = 0;
    way[s] = 1;
    priority_queue<ac> que;
    que.push({s, 0});
    while (!que.empty()) {
        ac f = que.top();
        que.pop();
        int u = f.v;
        if (dis[u] < f.c || vis[u]) continue;
        vis[u] = 1;
        for (auto it : edge[u]) {
            int v = it.v;
            long long c = f.c + it.c;
            if (dis[v] > c) {
                dis[v] = c;
                way[v] = way[u];
                que.push({v, c});
            }else if (dis[v] == c) (way[v] += way[u]) %= mod;
        }
    }
}
int main() {
    int n, m, s, e;
    scanf("%d %d %d %d", &n, &m, &s, &e);
    for (int i = 0, u,v,c; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &c);
        g[u].push_back({v, c, i});
        rg[v].push_back({u, c, i});
    }
    Dijkstra(s, e, dis, way, g);
    Dijkstra(e, s, rdis, rway, rg);
    for (int i = 1; i <= n; ++i) {
        for (auto it : g[i]) {
            int v = it.v;
            int c = it.c;
            long long tmp = c + dis[i] + rdis[v] - dis[e] + 1;
            if (dis[i] + c + rdis[v] == dis[e] && (way[i] * rway[v]) % mod == way[e]) ans[it.id] = -1;
            else if (tmp < c) ans[it.id] = tmp;
            else ans[it.id] = -2;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (ans[i] == -1) puts("YES");
        else if (ans[i] == -2) puts("NO");
        else printf("CAN %lld\n", ans[i]);
    }
    return 0;
}
```

