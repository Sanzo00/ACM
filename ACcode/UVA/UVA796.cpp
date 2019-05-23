#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int low[maxn], dfn[maxn], now;
vector<int> g[maxn];
set<P> ans;
void init() {
    now = 0;
    mem(dfn, 0);
    mem(low, 0);
}
void addedge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}
void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++now;
    int len = g[u].size();
    for (int i = 0; i < len; ++i) {
        int v = g[u][i];
        if (v == fa) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (dfn[u] < low[v]){
                ans.insert(make_pair(min(u,v), max(u,v)));
            }
        }else{
            low[u] = min(low[u], dfn[v]);
        }
    }
}
int main() {
    int n, x, y, m;
    while (scanf("%d", &n) != EOF) {
        init();
        ans.clear(); 
        for (int i = 0; i < n; ++i) g[i].clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d (%d)", &x, &m);
            for (int j = 0; j < m; ++j) {
                scanf("%d", &y);
                addedge(x, y);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (dfn[i]) continue;
            tarjan(i, i);
        }
        int sum = ans.size();
        printf("%d critical links\n", sum);
        for (auto it : ans) {
            printf("%d - %d\n", it.first, it.second);
        }
        puts("");
    }
    return 0;
}