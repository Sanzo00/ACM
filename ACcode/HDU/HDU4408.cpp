#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 105;

LL ans, A[maxn][maxn], B[maxn][maxn];
int n, m, mod, vis[maxn], ka[maxn], fa[maxn];
vector<int> g[maxn];
struct ac{
    int u, v, w;
    bool operator < (const ac &t) {
        return w < t.w;
    }
}a[maxn*10];

int find (int x, int f[]) {
    return (x == f[x]) ? x : f[x] = find(f[x], f);
}

LL det(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = (A[i][j] % mod + mod) % mod;
        }
    }
    LL tmp = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            while (A[j][i]) {
                // LL t = A[i][i] * inv(A[j][i], mod);
                LL t = A[i][i] / A[j][i];
                for (int k = i; k < n; ++k) {
                    A[i][k] = (A[i][k] - t * A[j][k]) % mod;
                    // swap(A[i][k], A[j][k]);
                }
                swap(A[i], A[j]);
                tmp *= -1;
            }
        }
        if (!A[i][i]) return 0;
        tmp = A[i][i] * tmp % mod;
    }
    return (tmp + mod) % mod;
}

void solve() {
    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0) continue;
        g[find(i, ka)].push_back(i);
        // cout << i << endl;
        vis[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        int len = g[i].size();
        // cout << i << " " << len << endl;
        if (len <= 1) continue;
        mem(A, 0);
        for (int j = 0; j < len; ++j) {
            for (int k = j+1; k < len; ++k) {
                int u = g[i][j];
                int v = g[i][k];
                if (B[u][v] == 0) continue;
                A[j][j] += B[u][v];
                A[k][k] += B[u][v];
                A[j][k] = (A[k][j] -= B[u][v]);
            }
        }
        // cout << det(len-1) << endl;
        ans = ans * det(len-1) % mod;
        for (int j = 0; j < len; ++j) fa[g[i][j]] = i;
    }
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        ka[i] = fa[i] = find(i, fa);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    while (cin >> n >> m >> mod, n) {
        for (int i = 0, u, v, w; i < m; ++i) {
            cin >> u >> v >> w;
            a[i] = {u-1, v-1, w};
        }
        sort(a, a + m);
        mem(B, 0);
        ans = 1;
        for (int i = 0; i < n; ++i) fa[i] = ka[i] = i;
        for (int i = 0, u, v; i <= m; ++i) {
            if ((i && (a[i].w != a[i-1].w)) || i == m) solve();
            u = find(a[i].u, fa);
            v = find(a[i].v, fa);
            if (u == v) continue;
            vis[u] = vis[v] = 1;
            B[u][v] = (B[v][u] += 1);
            // B[u][v]++;
            // B[v][u]++;
            u = find(u, ka);
            v = find(v, ka);
            if (u > v) swap(u, v);
            ka[v] = u;
        }
        int flag = 1;
        for (int i = 0; i < n; ++i) 
            if (fa[i] != fa[0]) flag = 0;
        if (flag) cout << ans % mod << endl;
        else cout << 0 << endl;
    }

    return 0;
}