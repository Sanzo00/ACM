#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
char g[maxn][maxn];
int Jx, Jy;
bool vis[maxn][maxn];
vector<pair<int,int>> F;
struct ac{
	int x, y, fire, c;
};
int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T, n, m;
	scanf("%d", &T);
	while (T--) {
		F.clear();
		queue<ac> que;
		memset(vis, 0, sizeof(vis));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%s", g[i]);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == 'F') que.push({i, j, 1, 0}), vis[i][j] = 1;
				if (g[i][j] == 'J') Jx = i, Jy = j;
			}
		}
		que.push({Jx, Jy, 0, 0});
		memset(vis, false, sizeof(vis));
		vis[Jx][Jy] = 1;
		int ans = -1;
		while (!que.empty()) {
			ac f = que.front();
			que.pop();
			for (int i = 0; i < 4; ++i) {
				int x = f.x + d[i][0];
				int y = f.y + d[i][1];
				int flag = 0;
				if (x < 0 || y < 0 || x >= n || y >= m) flag = 1;
				if (flag && f.fire) continue;
				if (flag && !f.fire) {ans = f.c + 1; goto here;}
				if (g[x][y] == '#' || vis[x][y]) continue;
				vis[x][y] = 1;
				que.push({x, y, f.fire, f.c+1});
			}
		}	
		here:
		if (ans != -1) printf("%d\n", ans);
		else puts("IMPOSSIBLE");
	}
	return 0;
}