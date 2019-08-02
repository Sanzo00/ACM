#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 5e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int girl[maxn], l[maxn], r[maxn], match[maxn];
vector<int> g[maxn];
int one(int x) {
	int cnt = 0;
	while (x) {
		if (x & 1) cnt++;
		x >>= 1;
	}
	return cnt;
}
int dfs(int x) {
	l[x] = 1;
	for (int i = 0; i < (int)g[x].size(); ++i) {
		int y = g[x][i];
		if (r[y]) continue;
		r[y] = 1;
		if (girl[y] == 0 || dfs(girl[y])) {
			girl[y] = x;
			return 1;
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			if (__builtin_popcount(a[i] ^ a[j]) == 1) {
				if (__builtin_parity(a[i])) g[i].push_back(j);
				else g[j].push_back(i);
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		memset(r, 0, sizeof(r));
		cnt += (match[i] = dfs(i));
	}
	cout << n - cnt << endl;
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	for (int i = 1; i <= n; ++i) {
		if (match[i]) continue;
		dfs(i);
	}
	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		if (__builtin_parity(a[i]) && l[i]) ans.push_back(a[i]);
		if (!__builtin_parity(a[i]) && !r[i]) ans.push_back(a[i]); 
	}
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << endl;

	return 0;
}