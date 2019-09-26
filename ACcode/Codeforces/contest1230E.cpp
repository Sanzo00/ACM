#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
#define P pair<long long,int>
using namespace std;
map<long long, int> all[maxn];
vector<int> g[maxn];
long long a[maxn], ans;
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a%b); 
}
void dfs(int u, int fa) {
    for (auto it : all[fa]) {
        long long l =  gcd(it.first, a[u]);
        long long r =  it.second;
        all[u][l] += r;
    }
    all[u][a[u]]++;
    for (auto it : all[u]) (ans += it.first * it.second) %= mod;
    for (int i = 0; i < (int)g[u].size(); ++i) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
    }
}
int main() {
   // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 0;
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}
