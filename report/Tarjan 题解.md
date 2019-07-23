<center><font size="6">Tarjan 题解</font></center>
### [A - Marriage Match II](#A)
### [B - Dining](#B)
### [C - A Plug for UNIX](#C)
### [D - Going Home](#D)
### [E - Minimum Cost](#E)
### [F - Power Network](#F)
### [G - Food](#G)
### [H - Control](#H)
### [I - Sabotage](#I)

<div STYLE="page-break-after: always;"></div>
<h3 id="A">A - 迷宫城堡 (HDU 1269)</h3>
#### 思路
判断整张图是否为强连通图
```cpp
#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;

vector<int> g[maxn];
int dfn[maxn], low[maxn], inStack[maxn], Stack[maxn]; 
int cnt, ts, len;
void tarjan(int u) {
	dfn[u] = low[u] = ++ts;
	inStack[u] = 1;
	Stack[len++] = u;
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}else if (inStack[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		++cnt;
		while (1) {
			int top = Stack[--len];
			inStack[top] = 0;
			if (top == u) break;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	while (cin >> n >> m, n||m) {
		// init
		for (int i = 0; i <= n; ++i) g[i].clear();
		len = cnt = ts = 0;
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(inStack, 0, sizeof(inStack));
		
		int a, b;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			g[a].push_back(b);
		}
		for (int i = 1; i <= n; ++i) {
			if (dfn[i]) continue;
			tarjan(i);
		}
		if (cnt == 1) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
```

<h3 id="B">B - Network  (POJ - 1144)</h3>
#### 题意
电话线公司要检查电话网中的关键点

#### 思路
求割点
数据的读入有点麻烦，首先是数字n表示n个节点，最多n行（0结束），每行第一个数字表示节点u之后的数字表示u的出边。
```cpp
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
const int maxn = 1e2 + 5;
using namespace std;

int low[maxn], dfn[maxn], ts, root;
vector<int> g[maxn];
set<int> ans;
void init() {
	ts = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
}
void addedge(int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}
void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++ts;
    int len = g[u].size();
    int son = 0;
    for (int i = 0; i < len; ++i) {
        int v = g[u][i];
        if (v == fa) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            son++;
            low[u] = min(low[u], low[v]);
            if (u == root && son > 1) {
                ans.insert(u);
            }else if (u != root && dfn[u] <= low[v]){
                ans.insert(u);
            }
        }else{
            low[u] = min(low[u], dfn[v]);
        }
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	while (scanf("%d", &n), n) {
		for (int i = 0; i <= n; ++i) g[i].clear();
		int u, v;
		while (scanf("%d", &u), u) {
			// 错误读入方式
			// while (scanf("%c", &c) && c != '\n') {
				// if (c == ' ') continue;
				// addedge(u, c - '0');
			// }
			while (getchar() != '\n') {
				scanf("%d", &v);
				addedge(u, v);
			}
		}
		ans.clear();
		init();
		for (int i = 1; i <= n; ++i) {
			root = i;
			if (dfn[i] == 0) tarjan(i, -1);
		}
		printf("%d\n", ans.size());
	}
	return 0;
}
```

<h3 id="C">C - Critical Links  (UVA - 796 )</h3>
#### 题意
求割边的个数，并输出割边

#### 思路
板子题

```cpp
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
const int maxn = 1e5 + 5;
using namespace std;

int low[maxn], dfn[maxn], ts;
vector<int> g[maxn];
vector<pair<int,int> > ans;
void init() {
	ts = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
}
void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++ts;
    int len = g[u].size();
    for (int i = 0; i < len; ++i) {
        int v = g[u][i];
        if (v == fa) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) ans.push_back(make_pair(min(u, v), max(u, v)));
        }else{
            low[u] = min(low[u], dfn[v]);
        }
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i <= n; ++i) g[i].clear();
		for (int i = 0; i < n; ++i) {
			int u, v, m;
			scanf("%d (%d)", &u, &m);
			for (int j = 0; j < m; ++j) {
				scanf("%d", &v);
				g[u].push_back(v);
			}
		}
		init();
		ans.clear();
		for (int i = 0; i < n; ++i) {
			if (dfn[i] == 0) tarjan(i, -1);
		}
		sort(ans.begin(), ans.end());
		int cnt = ans.size();
		cout << cnt << " critical links\n";
		for (int i = 0; i < cnt; ++i) {
			cout << ans[i].first << " - " << ans[i].second << endl;
		}
		cout << endl;
	}
	return 0;
}
```

<h3 id="D">A - Marriage Match II (HDU - 3081)</h3>
#### 题意


#### 思路

```cpp

```

<h3 id="A">A - Marriage Match II (HDU - 3081)</h3>
#### 题意


#### 思路

```cpp

```

<h3 id="A">A - Marriage Match II (HDU - 3081)</h3>
#### 题意


#### 思路

```cpp

```



<h3 id="A">A - Marriage Match II (HDU - 3081)</h3>
#### 题意


#### 思路

```cpp

```

<h3 id="A">A - Marriage Match II (HDU - 3081)</h3>
#### 题意


#### 思路

```cpp

```
