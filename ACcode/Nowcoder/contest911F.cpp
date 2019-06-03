#include <bits/stdc++.h>
#define LL  long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
const int maxn = 1e5 + 5;
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	double x, y;
	cin >> n;
	vector<int> L(n), R(n);
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		L[i] = x - y;
		R[i] = x + y;
	}
	sort(L.begin(), L.end());
	LL ans = 0;
	for (int i = 0; i < n; ++i) {
		auto it = upper_bound(L.begin(), L.end(), R[i]) - L.begin();
		ans += n - it;
	}
	cout << ans << endl;

    return 0;
}
