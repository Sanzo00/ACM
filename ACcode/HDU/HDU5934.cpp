#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 1e9;
using namespace std;
pair<long long,long long> a[maxn];
vector<long long> g[maxn];
long long d[maxn];
int c[maxn], cost[maxn];
int dfn[maxn], low[maxn], Stack[maxn], inStack[maxn], belong[maxn], in[maxn], ts, cnt, len;
int dis(int x, int y) {
	long long t = (a[x].first - a[y].first) * (a[x].first - a[y].first) + (a[x].second - a[y].second) * (a[x].second - a[y].second);
	if (t <= d[x] * d[x]) return 1;
	return 0;
}
void init(int n) {
	for (int i = 1; i <= n; ++i) g[i].clear();
	ts = cnt = len = 0;
	fill(dfn, dfn+n+1, 0);
	fill(in, in+n+1, 0);
	fill(cost, cost+n+1, inf);
	fill(inStack, inStack+n+1, 0);
}
void tarjan(int u) {
	dfn[u] = low[u] = ++ts;
	inStack[u] = 1;
	Stack[len++] = u;
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}else if (inStack[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		cnt++;
		while (1) {
			int top = Stack[--len];
			belong[top] = cnt;
			cost[cnt] = min(cost[cnt], c[top]);
			inStack[top] = 0;
			if (top == u) break;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T, kase = 1;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", kase++);
		int n;
		scanf("%d", &n);
		init(n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld %lld %lld %d", &a[i].first, &a[i].second, &d[i], &c[i]);
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j) continue;
				if (dis(i, j)) {
					g[i].push_back(j);
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (dfn[i]) continue;
			tarjan(i);
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < (int)g[i].size(); ++j) {
				if (belong[i] == belong[g[i][j]]) continue;
				in[belong[g[i][j]]]++;
			}
		}
		int ans = 0;
		for (int i = 1; i <= cnt; ++i) {
			if (in[i]) continue;
			ans += cost[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}