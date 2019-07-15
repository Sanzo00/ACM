#include <bits/stdc++.h>
const int maxn = 3e2 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int g[maxn][maxn], girl[maxn];
int usedx[maxn], usedy[maxn], topx[maxn], topy[maxn];
int n;
int dfs(int u) {
    usedx[u] = 1;
    for (int i = 1; i <= n; ++i) {
        if (usedy[i] || g[u][i] != topx[u] + topy[i]) continue;
        usedy[i] = 1;
        if (girl[i] == 0 || dfs(girl[i])) {
            girl[i] = u;
            return 1;
        }
    }
    return 0;
}
int km() {
    memset(girl, 0, sizeof(girl));
    for (int i = 1; i <= n; ++i) {
        while (1) {
            memset(usedx, 0, sizeof(usedx));
            memset(usedy, 0, sizeof(usedy));
            if (dfs(i)) break;
            int tmp = inf;
            for (int j = 1; j <= n; ++j) {
                if (!usedx[j]) continue;
                for (int k = 1; k <= n; ++k) {
                    if (usedy[k]) continue;
                    tmp = min(tmp, topx[j] + topy[k] - g[j][k]);
                }
            }
            for (int j = 1; j <= n; ++j) {
                if (usedx[j]) topx[j] -= tmp;
                if (usedy[j]) topy[j] += tmp;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
    	ans += g[girl[i]][i];
    }
    return ans;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> n) {
        memset(topy, 0, sizeof(topy));
        for (int i = 1; i <= n; ++i) {
            int tmp = -inf;
            for (int j = 1; j <= n; ++j) {
            	cin >> g[i][j];
                tmp = max(tmp, g[i][j]);
            }
            topx[i] = tmp;
        }
        cout << km() << endl;
    }
        
    return 0;
}
