#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 5e2 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
struct ac{
    int v, c, pre;
}edge[maxn*maxn];
int s, e;
int head[maxn<<1], dis[maxn<<1], curedge[maxn<<1], cnt;
void init() {
    mem(head, -1);
    cnt = 0;
}
void add(int u, int v, int c) {
    edge[cnt] = {v, c, head[u]};
    head[u] = cnt++;
}
bool bfs() {
    queue<int> que;
    que.push(s);
    mem(dis, 0);
    dis[s] = 1;
    while (!que.empty()) {
        int f = que.front();
        // printf("%d\n", f);
        que.pop();
        for (int i = head[f]; i != -1; i = edge[i].pre) {
            if (dis[edge[i].v] || edge[i].c == 0) continue;
            dis[edge[i].v] = dis[f] + 1;
            que.push(edge[i].v);
        }
    }
    return dis[e] > 0; 
}

int dfs(int now, int flow) {
    if (now == e || flow == 0) return flow;
    for (int &i = curedge[now]; i != -1; i = edge[i].pre) { // 当前弧优化
        if (dis[edge[i].v] != dis[now] + 1 || edge[i].c == 0) continue;
        int d = dfs(edge[i].v, min(flow, edge[i].c));
        if (d > 0) {
            edge[i].c -= d;
            edge[i^1].c += d;
            return d;
        }            
    }
    dis[now] = -1; // // 炸点优化
    return 0;
}
int Dinic() {
    int sum = 0, d;
    while (bfs()) {
        for (int i = 0; i <= e; ++i) curedge[i] = head[i];
        while (d = dfs(s, inf)) sum += d;
    }
    return sum;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, k, d, x;
    cin >> n >> m >> k;
    init();
    s = 0, e = n + m + 2;
    int se = n+m+1;
    for (int i = 1; i <= n; ++i) {
        cin >> d;
        for (int j = 1; j <= d; ++j) {
            cin >> x;
            add(i, x+n, 1);
            add(x+n, i, 0);
        }
    }
    for (int i = 1; i <= m; ++i) {
        add(i+n, e, 1);
        add(e, i+n, 0);
    }

    for (int i = 1; i <= n; ++i) {
        add(s, i, 1);
        add(i, s, 0);
        add(se, i, 1);
        add(i, se, 0);
    }
    add(s, se, k);
    add(se, s, 0);
    int ans = Dinic();
    cout << ans << endl;
    return 0;
}
