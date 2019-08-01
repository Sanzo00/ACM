#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 3e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
using namespace std;
long long dp[maxn][maxn][3];
char s[maxn], t[maxn];
int n, m, T;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 0;
            }
        }
        scanf("%d %d", &n, &m);
        scanf("%s %s", s+1, t+1);
        for (int i = 0; i < maxn; ++i) dp[i][0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][1] = dp[i-1][j][1];
                dp[i][j][2] = dp[i-1][j][2];
            }
            for (int j = 0; j < i; ++j) {
                if (j < m) {
                    if (s[i] > t[j+1]) dp[i][j+1][1] = (dp[i][j+1][1] + dp[i-1][j][0]) % mod;
                    if (s[i] == t[j+1]) dp[i][j+1][0] = (dp[i][j+1][0] + dp[i-1][j][0]) % mod;
                    if (s[i] < t[j+1] && (j != 0 || s[i] != '0')) dp[i][j+1][2] = (dp[i][j+1][2] + dp[i-1][j][0]) % mod;
                    dp[i][j+1][2] = (dp[i][j+1][2] + dp[i-1][j][2]) % mod;
                }else {
                    dp[i][j+1][1] = (dp[i][j+1][1] + dp[i-1][j][0]) % mod;
                    dp[i][j+1][1] = (dp[i][j+1][1] + dp[i-1][j][2]) % mod;
                }
                dp[i][j+1][1] = (dp[i][j+1][1] + dp[i-1][j][1]) % mod;
            }
        }
        long long ans = 0;
        for (int j = m; j <= n; ++j)  ans = (ans + dp[n][j][1]) % mod;
        printf("%lld\n", ans);
    }
 
    return 0;
}