#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, pos;
		cin >> n;
		vector<int> a(n), b;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] == 1) pos = i;
		} 
		for (int i = 0; i < n; ++i) {
			b.push_back(a[pos++]);
			pos %= n;
		}
		int f1 = 1, f2 = 1;
		for (int i = 1; i < n; ++i) {
			if (b[i] != b[i-1] + 1) f1 = 0;
		}
		reverse(b.begin(), b.end());
		for (int i = 0; i < n-1; ++i) {
			int t = i - 1;
			if (t < 0) t += n;
			if (b[i] != b[t] + 1) f2 = 0;
		}
		if (f1 + f2) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}