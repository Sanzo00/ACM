#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
 
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		int ans = abs(a - b) + x;
		ans = min(ans, n-1);
		cout << ans << endl;
	}
	return 0;
}
