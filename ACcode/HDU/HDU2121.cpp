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
struct ac{
    int u, v, w;
};

vector<ac> g(maxn);
int pre[maxn], vis[maxn], id[maxn], in[maxn];
int pos;
int zhuliu(int rt, int n, int m) {
    int ans = 0, u, v, w;
    while (1) {
        for (int i = 0; i < n; ++i) in[i] = inf;
        for (int i = 0; i < m; ++i) {
            u = g[i].u; v = g[i].v; w = g[i].w;
            if (u != v && w < in[v]) {
                pre[v] = u;
                in[v] = w;
                if (u == rt) pos = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i != rt && in[i] == inf) return -1;
        }
        int cnt = 0;
        mem(id, -1);
        mem(vis, -1);
        in[rt] = 0;
        for (int i = 0; i < n; ++i) {
            ans += in[i];
            u = i;
            while (vis[u] != i && id[u] == -1 && u != rt) {
                vis[u] = i;
                u = pre[u];
            }
            if (u != rt &&id[u] == -1) {
                v = pre[u];
                while (v != u) {
                    id[v] = cnt;
                    v = pre[v];
                }
                id[u] = cnt++;
            }
        }
        if (cnt == 0) break;
        for (int i = 0; i < n; ++i) {
            if (id[i] == -1) id[i] = cnt++;
        }
        for (int i = 0; i < m; ++i) {
            v = g[i].v;
            g[i].u = id[g[i].u];
            g[i].v = id[g[i].v];
            if (g[i].u != g[i].v) g[i].w -= in[v];
        }
        n = cnt;
        rt = id[rt];
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    while (cin >> n >> m) {
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            cin >> g[i].u >> g[i].v >> g[i].w;
            sum += g[i].w;
        }
        sum++;
        for (int i = m; i < n+m; ++i) {
            g[i].u = n;
            g[i].v = i-m;
            g[i].w = sum;
        }
        int ans = zhuliu(n, n+1, n+m);
        if (ans == -1 || ans - sum >= sum) cout << "impossible" << endl;
        else cout << ans - sum << " " << pos - m << endl;
        cout << endl;
    }
    return 0;
}
