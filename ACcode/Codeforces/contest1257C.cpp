#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], pos[maxn];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int ans = maxn;
		fill(pos, pos+maxn, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (pos[a[i]]) {
				ans = min(ans, i - pos[a[i]] + 1);
			}
			pos[a[i]] = i;
		}
		if (ans == maxn) ans = -1;
		cout << ans << endl;
	}
	return 0;
}
