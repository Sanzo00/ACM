#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int vis[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		fill(vis, vis+maxn, 0);
		long long n, a, b;
		string s;
		cin >> n >> a >> b >> s;
		vector<long long> v;
		for (int i = 0; i < n; ++i) {
			if(s[i] == '1') {
				vis[i] = vis[i+1] = 1;
			}
		}
		int L = 0, R = n;
		for (int i = 1; i <= n; ++i) {
			if (vis[i] == 0) L = i;
			else break;
		}
		for (int j = n; j >= 1; --j) {
			if (vis[j] == 0) R = j;
			else break;
		}
		for (int i = L+1; i <= R; ++i) {
			if (vis[i]) continue;
			int j = i;
			for (; j < n; ++j) if (vis[j]) break;
			if (j < n) {
				int t = j - i;
				if (t == 1 && vis[i-1] != vis[i+1]) continue;
				if (b * t <= 2 * a) {
					for (int k = i; k < j; ++k) vis[k] = 1;
				}
			}
			i = j;
		} 
		vis[0] = vis[n] = 0;
		long long ans1 = n+1, ans2 = n;
		for (int i = 1; i <= n; ++i) {
			if (vis[i] == 1) ans1++;
			if (vis[i] != vis[i-1]) ans2++;
		}
		ans1 *= b, ans2 *= a;
		cout << ans1 + ans2 << endl;
	}
	return 0;
}
