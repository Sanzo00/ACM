#include <bits/stdc++.h>
const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int d[6][2] = {0, 2, 1, 2, 2, 2, 2, 1, 2, 0, 1, 1};
int dd[4][2] = {1, -1, 1, 1, -1, 1, -1, -1};
int vis[maxn][maxn];
int n, m, flag;
int check(int x, int y) {
	return x <= 0 || y <= 0 || x > n || y > m || vis[x][y];
}
int num(int x, int y) {
	int cnt = 0, dx, dy;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 4; ++j) {
			dx = x + d[i][0] * dd[j][0];
			dy = y + d[i][1] * dd[j][1];
			if (check(dx, dy)) continue;
			cnt++;
		}
	}
	return cnt;
}
void dfs(int x, int y) {
	vis[x][y] = 1;
	if (flag) printf("%d %d\n", y, x);
	else printf("%d %d\n", x, y);
	int dx, dy, tx, ty, MIN = inf;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 4; ++j) {
			dx = x + d[i][0] * dd[j][0];
			dy = y + d[i][1] * dd[j][1];
			if (check(dx, dy)) continue;
			int t = num(dx, dy);
			if (t < MIN){
				MIN = t;
				tx = dx, ty = dy;
			}
		}
	}
	if (MIN != inf) dfs(tx, ty);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		fill(vis[0], vis[0]+maxn*maxn, 0);
		flag = 0;
		if (n > m) swap(n, m), flag = 1;
		if (n == 1 && m == 1) puts("YES\n 1 1");
		else if (n <= 1 || m <= 2) puts("NO");
		else puts("YES"), dfs(1, 1);
	}
	return 0;
}