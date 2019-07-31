#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
long long n;
vector<int> g[3];
void solve(int a) {
	if (a == 0) {
		cout << "1 " << n << endl;
		return;
	}
	long long p, q, r;
	if (g[a].size() >= 2) {
		p = 1ll << g[a][0];
		q = 1ll << g[a][1];
		cout << 2 << " " << n - p << " " << n - q << endl;
	}else if(g[a].size() >= 1) {
		p = 1ll << g[a][0];
		q = 1ll << g[a == 2 ? 1 : 2][0];
		cout << 2 << " " << n - p << " " << p + q << endl; 
	}else {
		p = 1ll << g[a == 2 ? 1 : 2][0];
		q = 1ll << g[a == 2 ? 1 : 2][1];
		r = 1ll << g[a == 2 ? 1 : 2][2];
		cout << 2 << " " << n - q - r << " " << q + p + r << endl;
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < 3; ++i) g[i].clear();
		for (long long i = 0; (1ll << i) <= n; ++i) {
			if (((1ll << i) & n ) == 0) continue;
			g[(1ll<<i) % 3].push_back(i);
		}
		solve(n % 3);
	}
	return 0;
}