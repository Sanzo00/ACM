#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int a[100][100], vis[100][100];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	while (cin >> n >> m) {
		memset(vis, 0, sizeof(vis));
		vector<pair<int,int>> ans;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> a[i][j];
			}
		}
		int flag = 1;
		for (int i = 1; i <= n && flag; ++i) {
			for (int j = 1; j <= m && flag; ++j) {
				if (a[i][j] != 0) {
					if (i == n || j == m) {continue;}
					int cnt = 0;
					if (a[i][j+1] == 0) cnt++;
					if (a[i+1][j+1] == 0) cnt++;
					if (a[i+1][j] == 0) cnt++;
					if (cnt) {continue;}
					a[i][j] = a[i][j+1] = a[i+1][j] = a[i+1][j+1] = 2;
					ans.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (a[i][j] == 1) flag = 0;
			}
		}
		if (flag == 0) {
			cout << -1 << endl;
			continue;
		}
		int len = ans.size();
		cout << len << endl;
		for (int i = 0; i < len; ++i) {
			cout << ans[i].first << " " << ans[i].second <<endl;
		}
	}
	return 0;
}
