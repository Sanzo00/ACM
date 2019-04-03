#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <time.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int inf = 0x3f3f3f3f;
int dis[501][501];
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0); 
    int T;
    // cin >> T;
    scanf("%d", &T);
    while (T--) {
        mem(dis, inf);
        int n, m, c;
        scanf("%d%d%d", &n, &m, &c);
        // cin >> n >> m >> c;
        for (int i = 1; i <= n; ++i) dis[i][i] = 0;
        for (int i = 0, u,v,w; i < m; ++i) {
            // cin >> u >> v >> w;
            scanf("%d%d%d", &u, &v, &w);
            if (w >= dis[u][v]) continue;
            dis[v][u] = dis[u][v] = min(dis[u][v], w);
        }
        for (int i = 0, u,v,w; i < c; ++i) {
            // cin >> u >> v >> w;
            scanf("%d%d%d", &u, &v, &w);
            dis[u][v] = min(dis[u][v], -w);
        }
        int flag = 0;
        for (int k = 1; k <= n &&!flag; ++k) {
            for (int i = 1; i <= n && !flag; ++i) {
                for (int j = 1; j <= n && !flag; ++j) {
                    int t = dis[i][k] + dis[k][j];
                    if (t < dis[i][j]) dis[i][j] = t;
                    // dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
                if (dis[i][i] < 0) flag = 1; 
            }
        }
        // if (flag) cout << "YES\n";
        // else cout << "NO\n";
        (flag) ? puts("YES") : puts("NO");
    }
    return 0;
}
