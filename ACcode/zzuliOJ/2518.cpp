#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 3e2 + 7;
LL a[maxn][maxn];
int dp[maxn];
int n, m, ans = 0;
int judge(int x, int y) {
    for (int i = 1; i <= m; ++i) {
        if (a[x][i] <= a[y][i]) return 0;
    }
    return 1;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) dp[i] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (judge(i, j)) {
                dp[j] = max(dp[j], dp[i]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    ans = n - ans;
    cout << ans << endl;
 
     
    return 0;
}