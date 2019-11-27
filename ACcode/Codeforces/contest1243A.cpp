#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
int a[maxn];
int main() {
	int k;
	cin >> k;
	while(k--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		sort(a+1, a+1+n);
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans = max(ans, min(n-i+1, a[i]));
		}
		cout << ans << endl;
	}
	return 0;
}
