#include <iostream>
#include <vector>
#define endl '\n'
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
vector<int> g[maxn];
int dfn[maxn], low[maxn], in[maxn], vis[maxn], Stack[maxn], ts, cnt, len;
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++ts;
	Stack[len++] = u;
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (v == fa) continue;
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		}else low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++cnt;
		while (1) {
			int v = Stack[--len];
			vis[v] = cnt;
			if (v == u) break;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ts = len = cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (dfn[i] == 0) tarjan(i, 0);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < (int)g[i].size(); ++j) {
			int v = g[i][j];
			if (vis[i] == vis[v]) continue;
			in[vis[v]]++;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (in[i] == 1) ans++;
	}
	ans = (ans + 1) / 2;
	cout << ans << endl;
	return 0;
}