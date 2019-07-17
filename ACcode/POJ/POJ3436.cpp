#include <iostream>
#include  <vector>
#include <cstring>
#include <queue>
#include <set>
const int maxn = 50 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int g[maxn][maxn], pre[maxn], vis[maxn];
int in[maxn][12], out[maxn][12], val[maxn];
int backup[maxn][maxn];
int n, m;
int used[maxn];
bool bfs(int s, int e) {
	memset(vis, 0, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	vis[s] = 1;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		for (int i = 0; i <= e; ++i) {
			if (g[f][i] && !vis[i]) {
				vis[i] = 1;
				pre[i] = f;
				que.push(i);
				if (i == e) return 1;
			}
		}
	}
	return 0;
}
int ek(int s, int e) {
	int ans = 0;
	while (bfs(s, e)) {
		int MIN = inf;
		for (int i = e; pre[i] != -1; i = pre[i]) {
			MIN = min(MIN, g[pre[i]][i]);
		}
		for (int i = e; pre[i] != -1; i = pre[i]) {
			g[pre[i]][i] -= MIN;
			g[i][pre[i]] += MIN;
		}
		ans += MIN;
	}
	return ans;
}
int check_in(int x) {
	for (int i = 0; i < n; ++i) {
		if (in[x][i] == 1) return 0;
	}
	return 1;
}
int check_out(int x) {
	for (int i = 0; i < n; ++i) {
		if(out[x][i] == 0) return 0;
	}
	return 1;
}
int check(int x, int y) {
	for (int i = 0; i < n; ++i) {
		if (in[y][i] == 2) continue;
		if (out[x][i] != in[y][i]) return 0;
	}
	return 1;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (cin >> n >> m) {
		memset(g, 0, sizeof(g));
		memset(used, 0, sizeof(used));
		for (int i = 1; i <= m; ++i) {
			cin >> val[i];
			for (int j = 0; j < n; ++j) cin >> in[i][j];
			for (int j = 0; j < n; ++j) cin >> out[i][j];
		}
		int s = 0, e = m + 1;
		for (int i = 1; i <= m; ++i) {
			if (check_in(i)) {
				g[s][i] = val[i];
				used[i] = 1;
			}
			if (check_out(i)) {
				g[i][e] = val[i];
				continue;
			}
			for (int j = 1; j <= m; ++j) {
				if (i == j || used[j]) continue;
				if (check(i, j)) g[i][j] = val[i];
			}
		}
		memcpy(backup, g, sizeof(g));
		int ans = ek(s, e);
		vector<int> all;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (backup[i][j] > g[i][j]) {
					all.push_back(i);
					all.push_back(j);
					all.push_back(backup[i][j] - g[i][j]);
				}
			}
		}
		cout << ans << " " << all.size() / 3 << endl;
		for (int i = 0; i < (int)all.size(); i += 3) {
			cout<< all[i] << " " << all[i+1] << " " << all[i+2] << endl;
		}
	}
	return 0;	
}
