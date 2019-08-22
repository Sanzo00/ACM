#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int g[102][102];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	memset(g, inf, sizeof(g));
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; ++j) {
			if (s[j-1] == '1') g[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; ++i) g[i][i] = 0;
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (g[i][j] > g[i][k] + g[k][j]){
				 	g[i][j] = g[i][k] + g[k][j];
				}
			}
		}
	}
	int m;
	cin >> m;
	vector<int> ans, a(m);
	for (auto &it : a) cin >> it;
	ans.push_back(a[0]);
	int s = a[0], e = a[m-1];
	int last = 0;
	for (int i = 1; i < m; ++i) {
		if (g[ans.back()][a[i]] != last + g[a[i-1]][a[i]]) ans.push_back(a[i-1]), last = g[a[i-1]][a[i]];
		else last += g[a[i-1]][a[i]];
	}
	if (ans[0] != s) ans.insert(ans.begin(), s);
	if (ans.back() != e) ans.push_back(e);
	cout << ans.size() << endl;
	for (auto it : ans) {
		cout << it << ' ';
	}
	return 0;
}