#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int a[maxn], b[maxn];
vector<int> g[maxn], g2[maxn];
int dfn[maxn], low[maxn], Stack[maxn], inStack[maxn], belong[maxn], in[maxn], ts, cnt, len;
int mp[maxn];
void init(int n) {
	for (int i = 0; i <= n; ++i) g[i].clear();
	for (int i = 0; i <= n; ++i) g2[i].clear();
	ts = cnt = len = 0;
	fill(dfn, dfn+n+1, 0);
	fill(in, in+n+1, 0);
	fill(mp, mp+n+1, -1);
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
			inStack[top] = 0;
			if (top == u) break;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	scanf("%d %d", &n, &m);
	init(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (i) g[a[i-1]].push_back(a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
		if (i) g[b[i-1]].push_back(b[i]);
	} 
	for (int i = 1; i <= n; ++i) {
		if (dfn[i]) continue;
		tarjan(i);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < (int)g[i].size(); ++j) {
			int v = g[i][j];
			if (belong[i] == belong[v]) continue;
			in[belong[v]]++;
			g2[belong[i]].push_back(belong[v]);
		}
	}
	if (m > cnt) puts("NO");
	else {
		puts("YES");
		queue<int> que;
		for (int i = 1; i <= cnt; ++i) {
			if (in[i] == 0) que.push(i);
		}
		char c = 'a' - 1;
		while (!que.empty() && m--) {
			int u = que.front();
			que.pop();
			mp[u] = ++c;
			for (int i = 0; i < (int)g2[u].size(); ++i) {
				int v = g2[u][i];
				if (--in[v] == 0) que.push(v);
			}
		}
		if (c < 'a') c = 'a';
		for (int i = 1; i <= cnt; ++i) {
			if (mp[i] == -1) mp[i] = c;
		}
		for (int i = 1; i <= n; ++i) {
			printf("%c", mp[belong[i]]);
		}
		puts("");
	}
	return 0;
}