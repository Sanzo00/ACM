#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int t;
	cin >> t;
	while (t--) {
		int b, p, f, h, c;
		cin >> b >> p >> f >> h >> c;
		int ans = 0, t;
		if (h >= c) {
			t = b / 2;
			t = min(t, p);
			p -= t;
			b -= t * 2;
			ans += h * t;
			t = b / 2;
			t = min(t, f);
			f -= t;
			b -= t * 2;
			ans += c * t;
		}else {
			t = b / 2;
			t = min(t, f);
			f -= t;
			b -= t * 2;
			ans += c * t;
			t = b / 2;
			t = min(t, p);
			p -= t;
			b -= t * 2;
			ans += h * t;
		}
		cout << ans << endl;
	}
	return 0;
}