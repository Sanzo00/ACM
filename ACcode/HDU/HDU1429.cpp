#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
using namespace std;
char g[25][25];
int sx, sy, ex, ey;
int n, m, t;
int vis[25][25][1<<10];
int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
struct ac{
	int x, y, c, key;
};
int check(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || g[x][y] == '*') return 1;
	return 0;
}
int bfs() {
	queue<ac> que;
	memset(vis, 0, sizeof(vis));
	que.push({sx, sy, 0, 0});
	vis[sx][sy][0] = 1;
	while (!que.empty()) {
		ac f = que.front();
		que.pop();
		int dx, dy;
		for (int i = 0; i < 4; ++i) {
			int key = f.key;
			dx = f.x + d[i][0];
			dy = f.y + d[i][1];
			if (check(dx, dy) || vis[dx][dy][key]) continue;
			vis[dx][dy][key] = 1;
			if (g[dx][dy] >= 'A' && g[dx][dy] <= 'J' && (key >> (g[dx][dy]-'A')) % 2 == 0) continue;
			if (g[dx][dy] >= 'a' && g[dx][dy] <= 'j') key |= 1 << (g[dx][dy] - 'a');
			if (g[dx][dy] == '^') return f.c+1 < t ? f.c+1 : -1;
			vis[dx][dy][key] = 1;
			que.push({dx, dy, f.c+1, key});
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (scanf("%d %d %d", &n, &m, &t) != EOF) {
		for (int i = 0; i < n; ++i) scanf("%s", g[i]);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == '@') sx = i, sy = j;
			}
		}
		int ans = bfs();
		printf("%d\n", ans);
	}
	return 0;
}