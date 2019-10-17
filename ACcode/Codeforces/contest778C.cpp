#include <bits/stdc++.h>
const int maxn = 3e5 + 5;
using namespace std;
int nex[maxn][26], ans[maxn];
int cnt, n;
int merge(int x, int y) {
	// printf("%d %d\n", x, y);
	if (x == 0 || y == 0) return x|y;
	int tmp = ++cnt;
	for (int i = 0; i < 26; ++i) nex[tmp][i] = merge(nex[x][i], nex[y][i]);
	return tmp;
}
void dfs(int u, int level) {
	int now = n + 1;
	cnt = now;
	for (int i = 0; i < 26; ++i) {
		if (nex[u][i]) now = merge(now, nex[u][i]);
	}
	// printf("u %d, level %d, cnt %d\n", u, level, cnt);
	ans[level] += cnt - n - 1;
	for (int i = 0; i < 26; ++i) {
		if (nex[u][i]) dfs(nex[u][i], level+1);
	}
}
int main() {
	// freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		char c;
		scanf("%d %d %c", &u, &v, &c);
		nex[u][c - 'a'] = v;
	}
	dfs(1, 1);
	// for (int i = 1; i <= n; ++i) {
		// printf("i %d, ans %d\n", i, ans[i]);
	// }
	int sz = 0, p;
	for (int i = 1; i <= n; ++i) {
		if (sz < ans[i]) {
			sz = ans[i];
			p = i;
		}
	}
	printf("%d\n%d\n", n-sz, p);
	
	return 0;
}
