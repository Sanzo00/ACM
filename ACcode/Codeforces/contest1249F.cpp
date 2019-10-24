#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
vector<int> g[maxn];
int a[maxn], b[maxn], dep[maxn], n, k;
void dfs(int u, int fa, int d) {
    dep[u] = d;
    for (auto v : g[u]) {
        if (fa == v) continue;
        dfs(v, u, d+1);
    }
}
void dfs(int u, int fa, int x, int d) {
    if (d > k) return;
    a[u] -= x;
    for (auto v : g[u]) {
        if (fa == v) continue;
        dfs(v, u, x, d+1);
    }
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++i) b[i] = i;
    sort(b+1, b+1+n, [&](int x, int y){
        return dep[x] > dep[y];
    });
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[b[i]] <= 0) continue;
        ans += a[b[i]];
        dfs(b[i], 0, a[b[i]], 0);
    }
    cout << ans << endl;
    return 0;
}