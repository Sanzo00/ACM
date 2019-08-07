#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	string x, y;
	while (T--) {
		cin >> x >> y;
		int lenx = x.size();
		int leny = y.size();
		if (lenx > leny) {
			int t = lenx - leny;
			while (t--) y = '0' + y;
		}else {
			int t = leny - lenx;
			while (t--) x = '0' + x;
		}
		int len = max(lenx, leny);
		int ans = 0;
		int pos;
		for (int i = len-1; i >= 0; --i) {
			if (y[i] == '1') {
				pos = i;
				break;
			}
		}
		for (int i = pos; i >= 0; --i) {
			if (x[i] == '1') break;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}