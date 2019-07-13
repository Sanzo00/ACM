#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int girl[maxn], used[maxn];
vector<int> g[maxn];
int dfs(int u) {
    for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (used[v]) continue;
		used[v] = 1;
		if (girl[v] == 0 || dfs(girl[v])) {
			girl[v] = u;
			return true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i <= n; ++i) {
			g[i].clear();
		}
		mem(girl, 0);
		int u, v, m;
		for (int j = 0; j < n; ++j) {
			scanf("%d: (%d)", &u, &m);
			for (int i = 0; i < m; ++i) {
				scanf("%d", &v);
				g[u].push_back(v);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			mem(used, 0);
			int t = dfs(i);
			ans += t;
		}
		ans = n - ans / 2;
		printf("%d\n", ans);
	}
	return 0;
}