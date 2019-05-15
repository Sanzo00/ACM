#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <time.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
vector<int> g[maxn];
int Stack[maxn], low[maxn], dfn[maxn], inStack[maxn], belong[maxn];
int vis[maxn], color[maxn];
int now, len, cnt;
void init() {
	now = len = cnt = 0;
	mem(inStack, 0);
	mem(belong, 0);
	mem(dfn, 0);
	mem(low, 0);
}
void tarjan(int x) {
	low[x] = dfn[x] = ++now;
	Stack[++len] = x;
	inStack[x] = 1;
	int tmp = g[x].size();
	for (int i = 0; i < tmp; ++i) {
		int y = g[x][i];
		if (!dfn[y]) tarjan(y), low[x] = min(low[x], low[y]);
		else if (inStack[y]) low[x] = min(low[x], low[y]);
	}
	if (dfn[x] == low[x]) {
		++cnt;
		int top;
		while (Stack[len] != x) {
			top = Stack[len--];
			belong[top] = cnt;
			inStack[top] = 0;
		}
		top = Stack[len--];
		belong[top] = cnt;
		inStack[top] = 0;
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 	int n, m;

 	while (cin >> n >> m) {
 		for (int i = 1; i <= n; ++i) {
 			g[i].clear();
 		}
	 	for (int i = 0, u,v; i < m; ++i) {
	 		cin >> u >> v;
	 		g[u].push_back(v);
	 	}
	 	init();
	 	for (int i = 1; i <= n; ++i) {
	 		if (dfn[i]) continue;
	 		tarjan(i);
	 	}
	 	mem(vis, 0);
	 	for (int i = 1; i <= n; ++i) {
	 		for (int j = 0; j < (int)g[i].size(); ++j) {
	 			int v = g[i][j];
	 			int l = belong[i];
	 			int r = belong[v];
	 			if (l == r) continue;
	 			vis[l] = 1;
	 		}
	 	}
	 	int sum = 0, ans = 0, flag;
	 	for (int i = 1; i <= n; ++i) {
	 		if (vis[belong[i]] == 0) {
	 			vis[belong[i]] = 1;
	 			sum++;
	 			flag = belong[i];
	 		}
	 	}
	 	for (int i = 1; i <= n; ++i) {
	 		if (belong[i] == flag) ans++;
	 	}
	 	if (sum != 1) ans = 0;
	 	cout << ans << endl;
 	}
	 	
    return 0;
}

/*
3 3
1 2
2 3
3 1

3 3
1 2
2 1
2 3

5 4
1 4
2 4
3 4
5 4

5 5
1 2
2 3
3 1
1 4
4 5

5 6
1 2
2 3
3 1
1 4
4 5
5 3

2 2
1 2
2 1

3 2
1 2
2 1

6 6
1 2
2 3
3 1
1 4
4 5
5 3

5 6
1 2
2 3
3 1
1 4
4 5
5 4

5 7
4 1
1 2
2 3
3 1
1 4
4 5
5 4

5 6
1 2
2 3
3 1
1 4
4 5	
5 1

7 9
1 2
2 3
3 1
4 5
5 6
6 4
4 7
7 1
1 7

6 6
1 2
2 3
3 1
4 5
5 6
6 4

4 4
1 2
2 3
3 1
1 4

4 4
1 2
2 3
3 1
4 1

5 6
1 2
2 3
3 1
5 1
5 4
3 4

7 9
1 2
2 3
3 1
5 1
5 4
3 4
4 7
7 6
6 4

3
1
1
1
5
2
0
0
2
5
5
4
0
1
3
1
3
*/
