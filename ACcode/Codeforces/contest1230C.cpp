#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
int vis[10][10], col[10];
vector<int> g[maxn];
int ans = 0;
int n, m;
void check() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (int)g[i].size(); ++j) {
            int v = g[i][j];
            int l = min(col[i], col[v]);
            int r = max(col[i], col[v]);
            vis[l][r] = 1; 
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 6; ++i){
        for (int j = i; j <= 6; ++j) {
            cnt += vis[i][j];
        }
    }
    ans = max(ans, cnt);
}
void dfs(int x) {
    if (x > n) {
        fill(vis[0], vis[0]+100, 0);
        check();
        return;
    }
    for (int i = 1; i <= 6; ++i) {
        col[x] = i;
        dfs(x+1);
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d %d\n", &n, &m);
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 0;
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
