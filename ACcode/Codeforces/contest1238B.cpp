#include <bits/stdc++.h>
const int maxn = 1e7 + 5;
using namespace std;
int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		long long n, r;
		scanf("%lld %lld", &n, &r);
		vector<long long> a(n);
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &a[i]);
		}
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		long long t = 0, ans = 0;
		for (int i = (int)a.size()-1; i >= 0; --i) {
			if (a[i] <= t) break;
			ans++;
			t += r;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
