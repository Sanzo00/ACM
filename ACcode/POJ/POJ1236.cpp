#include <iostream>
#include <vector>
#define endl '\n'
const int maxn = 1e2 + 5;
using namespace std;
vector<int> g[maxn];
int dfn[maxn], low[maxn], in[maxn], out[maxn], vis[maxn], inStack[maxn], Stack[maxn], ts, cnt, len;
void tarjan(int u) {
	dfn[u] = low[u] = ++ts;
	Stack[len++] = u;
	inStack[u] = 1;
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}else if(inStack[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++cnt;
		while (1) {
			int v = Stack[--len];
			inStack[v] = 0;
			vis[v] = cnt;
			if (v == u) break;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, d;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		while (cin >> d, d) {
			g[i].push_back(d);
		}
	}	
	len = cnt = ts = 0;
	for (int i = 1; i <= n; ++i) {
		if (dfn[i] == 0) tarjan(i);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < (int)g[i].size(); ++j) {
			int v = g[i][j];
			if (vis[i] == vis[v]) continue;
			in[vis[v]]++;
			out[vis[i]]++;
		}
	}
	if (cnt == 1) {
		cout << "1\n0\n";
		return 0;
	}
	int in_ = 0, out_ = 0;
	for (int i = 1; i <= cnt; ++i) {
		if (in[i] == 0) in_++;
		if (out[i] == 0) out_++;
	}
	cout << in_ << "\n" << max(in_, out_) << endl;
	return 0;
}