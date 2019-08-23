#include <bits/stdc++.h>
const int maxn = 1e2 + 1;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
using namespace std;
char g[maxn][maxn];
int sx, sy, ex, ey;
int n, m, t;
int vis[maxn][maxn][1<<5];
int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
struct ac{
	int x, y, c, key;
};
int check(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || g[x][y] == '#') return 1;
	return 0;
}
map<char,int> door, yao;
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
			if (door[g[dx][dy]] && (key >> door[g[dx][dy]]) % 2 == 0) continue;
			if (yao[g[dx][dy]]) key |= 1 << yao[g[dx][dy]];
			if (g[dx][dy] == 'X') return f.c + 1;
			vis[dx][dy][key] = 1;
			que.push({dx, dy, f.c+1, key});
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	door['B'] = 1, door['Y'] = 2, door['R'] = 3, door['G'] = 4;
	yao['b'] = 1, yao['y'] = 2, yao['r'] = 3, yao['g'] = 4;
	while (scanf("%d %d %d", &n, &m, &t), n) {
		for (int i = 0; i < n; ++i) scanf("%s", g[i]);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == '*') sx = i, sy = j;
			}
		}
		int ans = bfs();
		if (ans == -1) puts("The poor student is trapped!");
		else printf("Escape possible in %d steps.\n", ans);
	}
	return 0;
}