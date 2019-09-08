#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int ans[maxn], flag, len, Stack[maxn], inStack[maxn], vis[maxn];
struct ac{
    int v, c;
};
vector<ac> g[maxn];
void dfs(int u) {
    vis[u] = 1;
    inStack[u] = 1;
    Stack[len++] = u;
    for (int i = 0; i < (int)g[u].size(); ++i) {
        int v = g[u][i].v;
        int c = g[u][i].c;
        if (inStack[v]) ans[c] = 2, flag = 1;
        else if (vis[v] == 0)dfs(v), ans[c] = 1;
        else ans[c] = 1;
    }
    len--;
    inStack[u] = 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        g[u].push_back((ac){v, i});
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i);
    }
    printf("%d\n", flag+1);
    for (int i = 0; i < m; ++i) {
        if (i) printf(" "); 
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}