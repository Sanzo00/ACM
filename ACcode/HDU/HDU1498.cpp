#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
const int maxn = 1e2 + 5;
using namespace std;
int n, m;
int used[maxn], girl[maxn];
int g[maxn][maxn];
int dfs(int u, int c) {
	for (int i = 1; i <= n; ++i) {
		int v = g[u][i];
		if (v != c || used[i]) continue;
		used[i] = 1;
		if (girl[i] == 0 || dfs(girl[i], c)) {
			girl[i] = u;
			return 1;
		}
	}
	return 0;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	//freopen("in.txt", "r", stdin);
	while (cin >> n >> m, n&&m) {
		set<int> st;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> g[i][j];
				st.insert(g[i][j]);
			}
		}
		vector<int> ans;
		set<int>::iterator it = st.begin();
		while (it != st.end()){
			int cnt = 0;
			mem(girl, 0);
			for (int j = 1; j <= n; ++j) {
				mem(used, 0);
				cnt += dfs(j, *it);
			}
			if (cnt > m) ans.push_back(*it);
			++it;
		}
		sort(ans.begin(), ans.end());
		if (ans.empty()) {
			cout << -1;
		}else {
			for (int i = 0; i < (int)ans.size(); ++i) {
				if (i) cout << " ";
				cout << ans[i];
			}
		}
		cout << endl;
	}
	return 0;
}
