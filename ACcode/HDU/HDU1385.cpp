#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int val[maxn], path[maxn][maxn], g[maxn][maxn];
int min(int &x, int &y) {return x < y ? x : y;}
void Floyd(int n) {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (g[i][j] > g[i][k] + g[k][j] + val[k]) {
					path[i][j] = path[i][k];
					g[i][j] = g[i][k] + g[k][j] + val[k];
				}else if (g[i][j] == g[i][k] + g[k][j] + val[k] && path[i][j] > path[i][k]) {
					path[i][j] = path[i][k];
				}
			}
		}
	}
}
void print(int u, int v) {
	printf("%d", u);
	if (u != v) printf("-->");
	else {
		puts("");
		return;
	}
	print(path[u][v], v);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	while (scanf("%d", &n), n) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &g[i][j]);
				if (g[i][j] == -1) g[i][j] = inf;
				else path[i][j] = j;
			}
		}
		for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
		Floyd(n);
		int u, v;
		while (scanf("%d %d", &u, &v)) {
			if (u == -1 && v == -1) break;
			printf("From %d to %d :\n", u, v);
			printf("Path: ");
			print(u, v);
			printf("Total cost : %d\n\n", g[u][v]);
		}
	}
	return 0;
}