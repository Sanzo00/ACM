#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
struct ac{
    int v, c, nex;
}edge[maxn << 10];
int s, e;
int head[maxn], dis[maxn], curedge[maxn], cnt;
void init() {
    cnt = 0;
    fill(head, head+e+1, -1);
}
void add(int u, int v, int c) {
    edge[cnt] = {v, c, head[u]};
    head[u] = cnt++;
    edge[cnt] = {u, 0, head[v]};
    head[v] = cnt++;
}
bool bfs() {
    queue<int> que;
    que.push(s);
    fill(dis, dis+e+1, 0);
    dis[s] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = head[u]; i != -1; i = edge[i].nex) {
            int v = edge[i].v;
            int c = edge[i].c;
            if (dis[v] || !c) continue;
            dis[v] = dis[u] + 1;
            que.push(v);
        }
    }
    return dis[e] > 0;
}
int dfs(int u, int flow) {
    if (u == e || !flow) return flow;
    for (int &i = curedge[u]; i != -1; i = edge[i].nex) {
        int v = edge[i].v;
        int c = edge[i].c;
        if (dis[v] != dis[u] + 1 || !c) continue;
        int d = dfs(v, min(flow, c));
        if (d > 0) {
            edge[i].c -= d;
            edge[i^1].c += d;
            return d;
        }
    }
    dis[u] = -1;
    return 0;
}
int Dinic() {
    int sum = 0, d;
    while (bfs()) {
        for (int i = 0; i <= e; ++i) curedge[i] = head[i];
        while ((d = dfs(s, inf)) > 0) sum += d;
    }
    return sum;
}
int L[maxn], R[maxn], D[maxn];
int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case %d: ", kase);
        int n, m, m_ = 0;
        scanf("%d%d", &n, &m);
        int tot = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &D[i], &L[i], &R[i]);
            tot += D[i];
            m_ = max(m_, R[i]);
        }
        s = 0; e = n + m_ + 1;
        init();
        for (int i = 1; i <= n; ++i) {
            add(s, i, D[i]);
            for (int j = L[i]; j <= R[i]; ++j) add(i, n+j, 1);
        }
        for (int i = 1; i <= m_; ++i) add(i+n, e, m);
        puts(Dinic() == tot ? "Yes\n" : "No\n");
    }
    return 0;
}