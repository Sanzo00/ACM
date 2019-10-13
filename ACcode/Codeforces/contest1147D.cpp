#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 2e3 + 5;
char s[maxn];
int vis[maxn];
vector<pair<int,int>> g[maxn];
void add(int u, int v, int c) {
    g[u].push_back(make_pair(v, c));
    g[v].push_back(make_pair(u, c));
}
int check(int u) {
    if (vis[u] == -1) vis[u] = 0;
    for (int i = 0; i < (int)g[u].size(); ++i) {
        int v, c;
        tie(v, c) = g[u][i];
        if (vis[v] == -1) {
            vis[v] = c ? vis[u]^1 : vis[u];
            if (check(v) == 0) return 0;
        }else {
            if ((c && vis[v] == vis[u]) || (!c && vis[v] != vis[u])) return 0;
        }
    }
    return 1;
}
long long Pow(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1) {
            ret *= a;
            ret %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}
long long solve(int n, int m) {
    for (int i = 0; i < maxn; ++i) g[i].clear();
    for (int i = 1; i <= n/2; ++i) add(i, n+1-i, 0);
    for (int i = 1; i <= m/2; ++i) add(n+n-m+i, n+n+1-i, 0);
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == '?') continue;
        add(i, i+n, s[i-1]-'0');
    }
    add(2*n+1, 1, 0); // 2*n+1 : 1
    add(2*n+1, n+n-m+1, 0);
    for (int i = 1; i <= n-m; ++i) add(2*n+2, i+n, 0); // 2*n+2 : 0
    int cnt = 0;
    fill(vis, vis+maxn, -1);
    for (int i = 1; i <= 2*n+2; ++i) {
        if (vis[i] != -1) continue;
        if (check(i)) cnt++;
        else return 0;
    }
    return Pow(2, cnt-1);
}
int main() {
    scanf("%s", s);
    int len = strlen(s);
    long long ans = 0;
    for (int i = 1; i < len; ++i) {
        ans += solve(len, i);
        ans %= mod;
    }
    printf("%lld\n", ans % mod);
    return 0;
}
