#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#define endl '\n'
const int maxn = 5e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
vector<int> g[maxn];
int Stack[maxn], inStack[maxn], dfn[maxn], low[maxn], vis[maxn], len, cnt, ts;
int out[maxn];
void tarjan(int u) {
	low[u] = dfn[u] = ++ts;
	inStack[u] = 1;
	Stack[len++] = u;
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
		else if (inStack[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++cnt;
		while (1) {
			int top = Stack[--len];
			vis[top] = cnt;
			inStack[top] = 0;
			if (top == u) break;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	while (cin >> n, n) {
		cin >> m;
		ts = cnt = len = 0;
		for (int i = 1; i <= n; ++i) {
			g[i].clear();
			out[i] = dfn[i] = low[i] = inStack[maxn] = 0;
		}
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
		}
		for (int i = 1; i <= n; ++i){
			if (dfn[i]) continue;
			tarjan(i);
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < (int)g[i].size(); ++j) {
				int v = g[i][j];
				if (vis[i] == vis[v]) continue;
				out[vis[i]]++;
			}
		}
		set<int> st;
		for (int i = 1; i <= cnt; ++i) {
			if (out[i] == 0) st.insert(i);
		}
		vector<int> ans;
		for (int i = 1; i <= n; ++i) {
			if (st.find(vis[i]) != st.end()) ans.push_back(i);
		}
		int len = ans.size();
		for (int i = 0; i < len; ++i) {
			if (i > 0) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
		
	return 0;
}
