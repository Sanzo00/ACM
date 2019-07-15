#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (auto &v : a) {
			cin >> v;
		}
		sort(a.begin(), a.end());
		int t = (a.back() + a[0]) / 2;
		int ans = max(t - a[0], a.back() - t);
		if (ans > k) ans = -1;
		else {
			ans += k - ans + a[0];
		} 
		cout << ans << endl;
	}
	return 0;
}