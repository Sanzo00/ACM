#include <bits/stdc++.h>
const int maxn = 5e5 + 5;
using namespace std;
vector<tuple<int,int,int> >edge;
vector<pair<int,int> > g[maxn];
int pre[maxn], fa_e[maxn], fa_v[maxn], dep[maxn];
int ans[maxn];
int n, m, k;
int find(int x) {
    return (x == pre[x]) ? x : pre[x] = find(pre[x]);
}
void kruskal() {
    for (int i = 0; i <= n; ++i) pre[i] = i;
    for (int i = 0; i < (int)edge.size(); ++i) {
        int u, v, c;
        tie(u, v, c) = edge[i];
        int fu = find(u);
        int fv = find(v);
        if (fu == fv) continue;
        pre[fv] = fu;
        int id = i < k ? i+1 : k+1; // id = i+1 会超内存
        g[u].push_back(make_pair(v, id));
        g[v].push_back(make_pair(u, id));
    }
}
void dfs(int u) {
    for (auto it : g[u]) {
        int v, id;
        tie(v, id) = it;
        if (fa_v[v]) continue;
        fa_v[v] = u;
        fa_e[v] = id;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}
int main() {
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 0; i < k; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        edge.push_back(make_tuple(u, v, 0));
    }
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        edge.push_back(make_tuple(u, v, c));
    }
    kruskal();
    fa_v[1] = 1;
    fa_e[1] = 1;
    dfs(1);
    fill(ans, ans+n+1, -1);
    for (int i = 1; i <= n; ++i) pre[i] = i;
    for (int i = k; i < (int)edge.size(); ++i) {
        int u, v, c;
        tie(u, v, c) = edge[i];
        while (true) {
            u = find(u);
            v = find(v);
            if (u == v) break;
            if (dep[u] < dep[v]) swap(u, v);
            ans[fa_e[u]] = c;
            pre[u] = fa_v[u];
        }
    } 
    long long Ans = 0;
    for (int i = 1; i <= k; ++i) {
        if (ans[i] == -1) {
            Ans = -1;
            break;
        } 
        Ans += ans[i];
    }
    printf("%lld\n", Ans);
    return 0;
}