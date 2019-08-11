#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
vector<int> g[maxn];
int D[2][30][maxn], a[30], b[30], dis[maxn];
int n, m;
void bfs(int s, int *d, int x) {   
    for (int i = 1; i <= x; ++i) {
        d[i] = -1;
    }
    d[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = 0; i < (int)g[u].size(); ++i) {
            int v = g[u][i];
            if (d[v] != -1) continue;
            d[v] = d[u] + 1;
            que.push(v);
        }
    }
}
long long solve(int x, int y) {
    int mx = 0;
    for (int i = 1; i <= n; ++i) mx = max(mx, D[0][x][i] + D[1][y][i]);
    for (int i = n+1; i <= mx+n+1; ++i) g[i].clear();
    for (int i = n+1; i <= mx+n; ++i) g[i].push_back(i+1);
    for (int i = 1; i <= n; ++i) g[n+1+D[0][x][i]+D[1][y][i]].push_back(i);
    bfs(n+1, dis, mx+n+1);
    long long sum = 0;
    for (int i = 1; i <= n; ++i) sum += dis[i];
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T, Case = 1;
    scanf("%d", &T);
    while (T--) {
        printf("Case #%d: ", Case++);
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        scanf("%d", &a[0]);
        for (int i = 1; i <= a[0]; ++i) {
            scanf("%d", &a[i]);
            bfs(a[i], D[0][i], n);
        }
        scanf("%d", &b[0]);
        for (int i = 1; i <= b[0]; ++i) {
            scanf("%d", &b[i]);
            bfs(b[i], D[1][i], n);
        }
        long long P = 0;
        long long Q = a[0] * b[0] * n;
        for (int i = 1; i <= a[0]; ++i) {
            for (int j = 1; j <= b[0]; ++j) {
                P += solve(i, j);
            }
        }
        long long d = __gcd(P, Q);
        P /= d;
        Q /= d;
        P -= Q;
        if (Q == 1) printf("%lld", P);
        else printf("%lld/%lld", P, Q);
        puts("");
    }
    return 0;
}