#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 5e2 + 7;

int a[maxn][maxn];
vector<P> high[maxn * 2000];
int fa[maxn * maxn], n, m, q;
int d[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
set<int> st[maxn*maxn], ask[maxn*maxn];
int que[100005][4];
map<int, int> ans[maxn*maxn];

int Num(int x, int y) {
	return (x - 1) * m + y;
}

int judge(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > m) return 1;
	return 0;
}
int find(int x) {
	return (fa[x] == x) ? x : fa[x] = find(fa[x]);
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> q;
  	for (int i = 1; i <= n; ++i) {
  		for (int j = 1; j <= m; ++j) {
  			cin >> a[i][j];
  			high[a[i][j]].push_back(make_pair(i, j));
  		}
  	}
  	for (int i = 0; i < q; ++i) {
  		int x, y, s, e;
  		cin >> x >> y >> s >> e;
  		que[i][0] = x; que[i][1] = y; 
  		que[i][2] = s; que[i][3] = e;
  		ask[Num(x, y)].insert(Num(s, e));
  		ask[Num(s, e)].insert(Num(x, y));
  	}
  	for (int i = 1; i <= n * m; ++i) fa[i] = i, st[i].insert(i);
  	for (int i = 1; i <= 1000000; ++i) {
  		for (P it : high[i]) {
  			for (int k = 0; k < 4; ++k) {
  				int x = it.first + d[k][0];
  				int y = it.second + d[k][1];
  				if (judge(x, y) || a[x][y] > i) continue;
  				int fx = find(Num(it.first, it.second));
  				int fy = find(Num(x, y));
  				if (fx == fy) continue;
  				if (st[fx].size() < st[fy].size()) swap(fx, fy);
  				fa[fy] = fx;
  				for (int p : st[fy]) {
  					st[fx].insert(p);
  					for (int q : ask[p]) {

  						if (st[fx].find(q) == st[fx].end() || ans[p].find(q) != ans[p].end()) continue;
  						ans[q][p] = ans[p][q] = i;
  					}
  				}
  			}
  		}
  	}
  	for (int i = 0; i < q; ++i) {
  		int x = Num(que[i][0], que[i][1]);
  		int y = Num(que[i][2], que[i][3]);
  		if (x == y) ans[x][y] = a[que[i][0]][que[i][1]];
  		cout << ans[x][y] << '\n';
  	}

    return 0;
}