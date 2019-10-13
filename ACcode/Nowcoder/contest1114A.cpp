#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
long long dp[maxn][2];
int main() {
    int n;
    scanf("%d", &n);
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i-1][1] % mod;
        dp[i][1] = (dp[i-1][1] + dp[i-1][0]) % mod; 
    }
    long long ans = dp[n][0] + dp[n][1];
    printf("%lld\n", ans % mod);
    return 0;
}
