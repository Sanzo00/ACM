#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#define endl '\n'
const int maxn = 5e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int dfn[maxn], low[maxn], len, cnt, ts;
int vis[maxn], inStack[maxn], in[maxn], Stack[maxn];
int mp[maxn][maxn];
vector<int> g[maxn];
int F, R;
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++ts;
	Stack[len++] = u;
	inStack[u] = 1;
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (v == fa) continue;
		if (dfn[v] == 0) {
			tarjan(v, u);
			low[u] = min(low[v], low[u]);
		}else if(inStack[v])low[u] = min(dfn[v], low[u]);
	}
	if (dfn[u] == low[u]) {
		++cnt;
		while (1) {
			int t = Stack[--len];
			vis[t] = cnt;
			inStack[t] = 0;
			if (t == u) break;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	while (cin >> F >> R) {
		for (int i = 1; i <= F; ++i) {
			g[i].clear();
			vis[i] = dfn[i] = low[i] = in[i] = 0;
			len = cnt = ts = 0;
		}
		for (int i = 0; i < R; ++i) {
			int u, v;
			cin >> u >> v;
			if (mp[u][v]) continue;
			mp[u][v] = mp[v][u] = 1;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i = 1; i <= F; ++i) {
			if (dfn[i] == 0) tarjan(i, 0);
		}
		for (int i = 1; i <= F; ++i) {
			for (int j = 0; j < (int)g[i].size(); ++j) {
				if (vis[i] == vis[g[i][j]]) continue;
				in[vis[i]]++;
			}
		}
		int ans = 0;
		for (int i = 1; i <= F; ++i) {
			if (in[i] == 1) ans++;
		}
		ans = (ans + 1) / 2;
		cout << ans << endl;
	}
	return 0;
}