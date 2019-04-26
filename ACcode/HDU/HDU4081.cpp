#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1001;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int n, m;
struct ac{
    int u, v, w;
    ac(int u_=0, int v_=0, int w_=0){
        u = u_; v = v_; w = w_;
    }
    inline int Dis(ac x) {
        return ((x.u-u)*(x.u-u) + (x.v-v)*(x.v-v));
    }
};
int g[maxn][maxn], val[maxn], vis[maxn], dis[maxn];
int pre[maxn], maxd[maxn][maxn];
bool used[maxn][maxn];
    
double Count(int i, int j, double sum) {
    return (val[i] + val[j]) * 1.0 / (sum - sqrt(g[i][j]));
}
void prim(int s) {
    mem(maxd, 0);
    mem(vis, 0);
    mem(used, 0);
    for (int i = 0; i < n; ++i) {
        dis[i] = g[s][i];
        pre[i] = s;
    }

    vis[s] = 1;
    double sum = 0;
    for (int i = 1; i < n; ++i) {
        int u = -1, MIN = inf;
        for (int j = 0; j < n; ++j) {
            if (vis[j]) continue;
            if (MIN > dis[j]) {
                MIN = dis[j];
                u = j;
            }
        }
        if (u == -1) break;
        vis[u] = 1;
        sum += sqrt(MIN);
        used[pre[u]][u] = used[u][pre[u]] = 1;
        maxd[u][pre[u]] = maxd[pre[u]][u] = MIN;
        for (int j = 0; j < n; ++j) {
            if (j == u) continue;
            if (vis[j]) {
                maxd[u][j] = maxd[j][u] = max(maxd[pre[u]][j], MIN);
            }
            if (vis[j] == 0 && dis[j] > g[u][j]) {
                dis[j] = g[u][j];
                pre[j] = u;
            }
        } 
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (used[i][j]) ans = max(ans, Count(i, j, sum));
            else ans = max(ans, Count(i, j, sum - sqrt(maxd[i][j]) + sqrt(g[i][j])));
        }
    }
    printf("%.2lf\n", ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector<ac> t(n);
        mem(g, inf);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &t[i].u, &t[i].v, &val[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                g[i][j] = g[j][i] = t[i].Dis(t[j]);
            }
        }
        prim(0);
    }
    return 0;
}