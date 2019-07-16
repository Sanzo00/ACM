#include <bits/stdc++.h>
const int maxn = 2e2 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int n, m, k;
int usex[maxn], usey[maxn], topx[maxn], topy[maxn], slack[maxn];
int girl[maxn], g[maxn][maxn];
int dfs(int x) {
	usex[x] = 1;
	for (int i = 1; i <= m; ++i) {
		if (usey[i]) continue;
		int tmp = topx[x] + topy[i] - g[x][i]; 
		if (tmp != 0) { 
			slack[i] = min(tmp, slack[i]);
		}else {
			usey[i] = 1; 
			if (girl[i] == -1 || dfs(girl[i])) {
				girl[i] = x;
				return 1;
			}
		}
	}
	return 0;
}
int km() {
	memset(girl, -1, sizeof(girl));
	memset(topy, 0, sizeof(topy));
	for (int i = 0; i <= n; ++i) topx[i] = -inf;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			topx[i] = max(topx[i], g[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		memset(slack, inf, sizeof(slack));
		while (1) {
			memset(usex, 0, sizeof(usex));
			memset(usey, 0, sizeof(usey));
			if (dfs(i)) break;
			int tmp = inf;
			for (int j = 1; j <= m; ++j) {
				if (usey[j]) continue;
				tmp = min(tmp, slack[j]);
			}
			if (tmp == inf) return -1;
			for (int j = 1; j <= n; ++j) {
				if (usex[j]) topx[j] -= tmp;
			}
			for (int j = 1; j <= m; ++j) {
				if (usey[j]) topy[j] += tmp;
				else slack[j] -= tmp;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		if (girl[i] != -1) ans += g[girl[i]][i];
	}
	return -ans;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while(cin >> n >> m >> k) {
		fill(g[0], g[0]+maxn*maxn, -inf);
		map<string, int> Lv, Cao;
		int L = 1, R = 1;
		for (int i = 0; i < k; ++i) {
			string s1, s2;
			int t;
			cin >> s1 >> s2 >> t;
			if (Lv[s1] == 0)  Lv[s1] = L++;
			if (Cao[s2] == 0) Cao[s2] = R++;
			g[Lv[s1]][Cao[s2]] = -t;
		}	
		cout << km() << endl;
	}
	return 0;
}
