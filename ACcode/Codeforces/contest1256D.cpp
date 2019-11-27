#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main() {
	int q;
	cin >> q;
	while (q--) {
		long long n, k;
		cin >> n >> k;
		string s, t;
		cin >> s;
		long long cnt = 0, tmp = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				int tt = abs(i - tmp);
				if (tt + cnt <= k) {
					cnt += tt;
					tmp++;
				}else {
					for (int j = 0; j < tmp; ++j) t += '0';
					int r = k - cnt;
					r = i - r;
					for (int j = tmp; j < r; ++j) t += '1';
					t += '0';
					for (int j = r+1; j <= i; ++j) t += '1';
					for (int j = i+1; j < n; ++j) t += s[j];
					break;
				}
			}
		}
		if (t.empty()) {
			for (int i = 0; i < tmp; ++i) cout << 0;
			for (int i = 0; i < n-tmp; ++i) cout << 1;
			cout << endl;
		}else cout << t << endl;
 
	}
	return 0;
}
