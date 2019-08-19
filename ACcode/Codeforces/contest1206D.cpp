#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
vector<int> g[maxn], cnt[61];
int ans;
int vis[maxn], used[maxn], dep[maxn];
void dfs(int u, int fa) {
	vis[u] = used[u] = 1;
	for (auto v : g[u]) {
		if (v == fa) continue;
		if (vis[v]) ans = min(ans, dep[u] - dep[v] + 1);
		else dep[v] = dep[u] + 1, dfs(v, u);
	}
	vis[u] = 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 60; j >= 0; --j) {
			if ((a[i] >> j) & 1) {
				cnt[j].push_back(i);
			}
		}
	}
	for (int i = 0; i <= 60; ++i) {
		if (cnt[i].size() >= 3) {
			cout << 3 << endl;
			return 0;
		}
		if (cnt[i].size() <= 1) continue;
		g[cnt[i][0]].push_back(cnt[i][1]);
		g[cnt[i][1]].push_back(cnt[i][0]);
	}
	ans = 1e9;
	fill(used, used+maxn, 0);
	fill(used, used+maxn, 0);
	for (int i = 0; i < n; ++i) {
		if (used[i]) continue;
		dep[i] = 0;
		dfs(i, -1);
	}
	if (ans == 1e9) ans = -1;
	cout << ans << endl;
	return 0;
}