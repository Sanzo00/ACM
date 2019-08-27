#include <bits/stdc++.h>
#define lowbit(a) (a&(-a))
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
using namespace std;
char dp[1 << 26];
int e[26];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		e[u] |= 1 << v;
		e[v] |= 1 << u;
	}
	for (int i = 0; i < n; ++i) {
		e[i] |= 1 << i;
		e[i] = ~e[i];
	}
	long long ans = 0;
	for (int i = 1; i < (1 << n); ++i) {
		int t = __builtin_ffs(i) - 1;
		dp[i] = max((int)dp[i ^ (1<<t)], (int)dp[i & e[t]] + 1);
		ans += dp[i];
	}
	printf("%lld\n", ans);
	return 0;
}