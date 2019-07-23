#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;

vector<int> g[maxn];
int dfn[maxn], low[maxn], inStack[maxn], Stack[maxn]; 
int cnt, ts, len;
void tarjan(int u) {
	dfn[u] = low[u] = ++ts;
	inStack[u] = 1;
	Stack[len++] = u;
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}else if (inStack[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		++cnt;
		while (1) {
			int top = Stack[--len];
			inStack[top] = 0;
			if (top == u) break;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	while (cin >> n >> m, n||m) {
		// init
		for (int i = 0; i <= n; ++i) g[i].clear();
		len = cnt = ts = 0;
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(inStack, 0, sizeof(inStack));
		
		int a, b;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			g[a].push_back(b);
		}
		for (int i = 1; i <= n; ++i) {
			if (dfn[i]) continue;
			tarjan(i);
		}
		if (cnt == 1) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}