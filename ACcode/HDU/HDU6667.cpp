#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
long long  a[maxn], b[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		long long sum = 0;
		for (int i = 1; i <= n; ++i) scanf("%lld %lld", &a[i], &b[i]), sum += b[i];
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			long long tmp = sum;
			if (ans < b[i]) tmp -= b[i] - ans;
			ans += min(tmp, a[i]);
			sum -= min(tmp, a[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}