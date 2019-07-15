#include <bits/stdc++.h>
const int maxn = 1e2 + 5;
using namespace std;
int used[maxn*100], girl[maxn*100];
int a[maxn][maxn];
vector<int> g[maxn * 100];
int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int dfs(int u) {
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (used[v]) continue;
		used[v] = 1;
		if (girl[v] == 0 || dfs(girl[v])) {
			girl[v] = u;
			return 1;
		}
	}
	return 0;
}
int n, m, k;
int id(int x, int y) {return (x - 1) * m + y;}
void print(int x) {
	int l = x / m + 1;
	int r = x % m;
	if (r == 0) r = m, l--;
	cout << "(" << l << "," << r << ")";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (cin >> n >> m, n) {
		cin >> k;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < k; ++i) {
			int u, v;
			cin >> u >> v;
			a[u][v] = 1; 
		}
		for (int i = 0; i <= n * m; ++i) g[i].clear();
		memset(girl, 0, sizeof(girl));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (a[i][j] == 1 || (i + j) & 1) continue;
				for (int q = 0; q < 4; ++q) {
					int x = i + d[q][0];
					int y = j + d[q][1];
					if (x > n || y > m || x < 1 || y < 1 || a[x][y] == 1) continue;
					g[id(i, j)].push_back(id(x, y));
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n * m; ++i) {
			memset(used, 0, sizeof(used));
			cnt += dfs(i);
		}
		cout << cnt << endl;
		for (int i = 1; i <= n * m; ++i) {
			if (!girl[i]) continue;
			print(girl[i]);
			cout << "--";
			print(i);
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
