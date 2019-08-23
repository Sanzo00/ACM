#include <bits/stdc++.h>
const int maxn = 3e5 + 5;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
using namespace std;
long long f[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	f[0] = 1;
	for (int i = 1;  i < maxn; ++i) f[i] = f[i-1] * i % mod;
	int n;
	cin >> n;
	vector<pair<int,int>> all(n);
	for (int i = 0; i < n; ++i) {
		cin >> all[i].first >> all[i].second;
	}
	sort(all.begin(), all.end());
	long long a = 1, b = 1, c = 1;
	for (int i = 0; i < n;) {
		int j = i;
		while (j < n && all[j].first == all[i].first) ++j;
		a = a * f[j - i] % mod;
		i = j;
	}
	sort(all.begin(), all.end(), [&](const pair<int,int> t1, const pair<int,int> t2){
		return t1.second < t2.second;
	});
	for (int i = 0; i < n;) {
		int j = i;
		while (j < n && all[j].second == all[i].second) ++j;
		b = b * f[j - i] % mod;
		i = j;
	}
	sort(all.begin(), all.end());
	for (int i = 1; i < n; ++i) {
		if (all[i].second < all[i-1].second) c = 0;
	}
	long long tmp = 1;
	for (int i = 1; i < n; ++i) {
		if (all[i] == all[i-1]) tmp++;
		else {
			c = c * f[tmp] % mod;
			tmp = 1;
		}
	}
	c = c * f[tmp] % mod;
	long long ans = (f[n] - a - b + c) % mod;
	ans = (ans + mod) % mod;
	cout << ans << endl;
	return 0;
}
