#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
using namespace std;
vector<int> g[maxn];
int a[maxn];
void dfs(int u, int d) {
    a[u] = d;
    for (int i = 0; i < (int)g[u].size(); ++i) {
        int v = g[u][i];
        if (a[v]) continue;
        dfs(v, min(d, v));
    }
}
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int last = 0, op, d;
    scanf("%d %d", &op, &d); 
    d = (d + last) % n + 1;
    dfs(d, d);
    int tmp = d;
    while (--q) {
        scanf("%d %d", &op, &d);
        d = (d + last) % n + 1;
        if (op == 1) tmp = min(tmp, a[d]);
        else {
            last = min(tmp, a[d]);
            printf("%d\n", last);
        }
    }
    return 0;
}
