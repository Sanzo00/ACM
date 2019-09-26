#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
vector<int> in[maxn];
int deg[maxn];
int main() {
    int n, m, q;
    scanf("%d %d", &n, &m);
    for (int i = 0, u,v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        if (u > v) swap(u, v);
        in[u].push_back(v);
        deg[u]++;
        deg[v]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)  ans += 1ll * in[i].size() * (deg[i] - in[i].size());
    printf("%lld\n", ans);
    scanf("%d", &q);
    for (int i = 0,x; i < q; ++i) {
        scanf("%d", &x);
        ans -= 1ll * in[x].size() * (deg[x] - in[x].size());
        for (auto it : in[x]) {
            ans -= 1ll * in[it].size() * (deg[it] - in[it].size());
            in[it].push_back(x);
            ans += 1ll * in[it].size() * (deg[it] - in[it].size());
        }
        in[x].clear();
        printf("%lld\n", ans);
    }
    return 0;
}
