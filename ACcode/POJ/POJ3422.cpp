#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <algorithm>
const int maxn = 5e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
#define pii pair<int,int>
int preE[maxn], preV[maxn], dis[maxn], head[maxn], vis[maxn], h[maxn], cnt;
void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
}
struct ac{
    int v, c, cost, nex;
}edge[maxn << 2];
void addedge(int u, int v, int c, int cost) {
    edge[cnt] = {v, c, cost, head[u]};
    head[u] = cnt++;
    edge[cnt] = {u, 0, -cost, head[v]};
    head[v] = cnt++;
}
int Dijkstra(int s, int e) {
    memset(dis, inf, sizeof(dis));
    preE[s] = -1, dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> >que;
    que.push(pii(0, s));
    while (!que.empty()) {
        pii top = que.top();
        que.pop();
        int u = top.second;
        if (dis[u] < top.first) continue;
        for (int i = head[u]; i != -1; i = edge[i].nex) {
            int v = edge[i].v;
            int cost = edge[i].cost;
            int c = edge[i].c;
            if (c > 0 && dis[v] > dis[u] + cost + h[u] - h[v]) {
                dis[v] = dis[u] + cost + h[u] - h[v];
                preE[v] = i;
                preV[v] = u;
                que.push(pii(dis[v], v));
            }
        }
    }
    return dis[e] != inf;
}
int MincostMaxflow(int s, int e, int &cost) {
    int maxflow = 0;
    memset(h, 0, sizeof(h));
    while (Dijkstra(s, e)) { 
        for (int i = 0; i <= e; ++i) h[i] += dis[i];
        int flow = inf; 
        for (int i = e; i != s; i = preV[i]) {
            flow = min(flow, edge[preE[i]].c); // 取最小的流量
        }
        for (int i = e; i != s; i = preV[i]) {
            edge[preE[i]].c -= flow;
            edge[preE[i]^1].c += flow;
        }
        cost += flow * h[e];
        maxflow += flow;
    }
    return maxflow; // 返回最大流
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k, d;
    scanf("%d %d", &n, &k);
    init();
    int s = 0, e = n * n * 2;
    addedge(s, 1, k, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &d);
            int now = (i-1) * n + j;
            if (k > 0) addedge(now*2-1, now*2, 1, -d);
            if (k > 1) addedge(now*2-1, now*2, k-1, 0);
            
            if (j+1 <= n) addedge(now*2, now*2+1, k, 0);
            if (i+1 <= n) addedge(now*2, now*2+n*2-1, k, 0);
        }
    }
    int cost = 0;
    MincostMaxflow(s, e, cost);
    printf("%d\n", -cost);
    return 0;
}