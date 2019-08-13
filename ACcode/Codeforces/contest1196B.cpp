#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int a[maxn], b[maxn]; 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		int len = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] & 1) b[len++] = i;
		}
		if (b[len-1] != n) b[len-1] = n;
		if (len < m || (len - m) % 2 != 0) cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = len-m; i < len; ++i) {
				if (i > len-m) cout << " ";
				cout << b[i]; 
			}
			cout << endl;
		} 
	}
	return 0;
}