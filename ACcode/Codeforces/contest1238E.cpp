#include <bits/stdc++.h>
const int maxn = 2e6 + 5;
using namespace std;
char s[maxn];
int dp[maxn], g[30][30];
int main() {
    int n, m;
    scanf("%d %d %s", &n, &m, s);
    for (int i = 1; i < n; ++i) {
        g[s[i]-'a'][s[i-1]-'a']++;
        g[s[i-1]-'a'][s[i]-'a']++;
    }
    dp[0] = 0;
    for (int i = 1; i < (1<<m); ++i) { // 枚举确定的状态
        int cnt = 0;
        dp[i] = 1e9;
        for (int j = 0; j < m; ++j) { // 确定的字符 和 未确定的字符 贡献++
            for (int k = j+1; k < m; ++k) {
                if ((i>>j & 1) ^ (i>>k & 1)) {
                    cnt += g[j][k];
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            if (i >> j & 1) {
                dp[i] = min(dp[i], dp[i - (1<<j)] + cnt);
            }
        }
    }
    printf("%d\n", dp[(1<<m) - 1]);
    return 0;
}

