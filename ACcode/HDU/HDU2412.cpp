#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
vector<int> g[maxn];
int dp[maxn][2];
int flag[maxn][2];
void dfs(int u) {
	int c0 = 0, c1 = 0;
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		dfs(g[u][i]);
		c0 += dp[v][0];
		c1 += max(dp[v][1], dp[v][0]);
		if (dp[v][1] > dp[v][0] && flag[v][1] == 0) flag[u][0] = 0;
		if (dp[v][1] < dp[v][0] && flag[v][0] == 0) flag[u][0] = 0;
		if (dp[v][1] == dp[v][0]) flag[u][0] = 0;
		if (flag[v][0] == 0) flag[u][1] = 0; 
	}
	dp[u][0] = c1;
	dp[u][1] = c0 + 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	while (cin >> n, n) {
		for (int i = 1; i <= n; ++i) g[i].clear();
		fill(dp[0], dp[0]+n*2+2, 0);
		fill(flag[0], flag[0]+n*2+2, 1);
		int cnt = 0;
		map<string, int> mp;
		string s, t;
		cin >> s;
		if (mp[s] == 0) mp[s] = ++cnt;
		for (int i = 1; i < n; ++i) {
			cin >> s >> t;
			if (mp[s] == 0) mp[s] = ++cnt;
			if (mp[t] == 0) mp[t] = ++cnt;
			g[mp[t]].push_back(mp[s]);
		}
		dfs(1);
		if (dp[1][1] == dp[1][0]) cout << dp[1][1] << " No\n";
		else if (dp[1][1] > dp[1][0]) cout << dp[1][1] << " " << (flag[1][1] ? "Yes": "No") << endl;
		else cout << dp[1][0] << " " << (flag[1][0] ? "Yes":"No") << endl;
	}
	return 0;
}