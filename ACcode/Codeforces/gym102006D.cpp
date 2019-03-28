#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 515;
char g[maxn][maxn];
LL dp[maxn][maxn];
LL ss[maxn], num[maxn];
int n, m;

LL dfs(int x, int y) {
    if (x > n) return ss[y];
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = max(dp[x][y], dfs(x+1, y));
    if (g[x][y] != '.') {
        if (y-1 >= 1) dp[x][y] = max(dp[x][y], dfs(x+1, y-1));
        if (y+1 <= m) dp[x][y] = max(dp[x][y], dfs(x+1, y+1));
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    freopen("balls.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) cin >> num[i];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> g[i][j];
            }
        }
        for (int i = 1; i <= m; ++i) cin >> ss[i];
        memset(dp, -1, sizeof(dp));
        LL ans = 0;
        for (int i = 1; i <= m; ++i) ans += dfs(1, i) * num[i];
        cout << ans << endl;
    }

    return 0;
}