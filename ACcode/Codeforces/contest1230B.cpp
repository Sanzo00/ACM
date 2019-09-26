#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s;
	int n, m;
	while (cin >> n >> m >> s) {
		if (n == 1) {
			if (m <= 0) cout << s << endl;
			else cout << 0 << endl;
			continue;
		}
		int flag = 0;
		if (s[0] != '1' && m) {
			s[0] = '1';
			m--;
			flag = 1;
		}
		for (int i = 1; i < n && m; ++i) {
			if (s[i] != '0') {
				s[i] = '0';
				m--;
			}
		}
		cout << s << endl;
	}
	return 0;
}
