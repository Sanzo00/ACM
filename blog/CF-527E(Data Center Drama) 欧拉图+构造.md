## CF-527E(Data Center Drama) 欧拉图+构造

[题目链接](https://codeforces.com/contest/527/problem/E)

#### 题意

$n$个电脑$m$个网线(存在环和重边),你可以添加最少数量的网线并规定他们的方向,使每个点的出度都为偶数并且每个计算机相互连接.输出任意一种方案.

#### 思路

首先将所有的点补成偶度,考虑到欧拉回路,可以保证所有的计算机相互连接.

把欧拉回路想象成简单环, 让偶数编号的点指向两边,可以保证出度为偶数

```cpp
#include <bits/stdc++.h>
const int maxn = 5e5 + 5;
using namespace std;
vector<pair<int,int>> g[maxn];
pair<int,int> edge[maxn];
int in[maxn], now[maxn], vis[maxn];
vector<int> tour;
void dfs(int u) {
    for (; now[u] < (int)g[u].size(); ++now[u]) {
        int v, id;
        tie(v, id) = g[u][now[u]];
        if (vis[id]) continue;
        vis[id] = 1;
        dfs(v);
    }
    tour.push_back(u);
}
int main() {
    int n, m, cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0, u,v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        edge[cnt++] = make_pair(u, v);
        in[u]++;
        in[v]++;
    } 
    vector<int> odd;
    for (int i = 1; i <= n; ++i) if (in[i] & 1) odd.push_back(i);
    int len = odd.size();
    for (int i = 0; i < len; i += 2) {
        edge[cnt++] = make_pair(odd[i], odd[i+1]);
    }
    if (cnt & 1) edge[cnt++] = make_pair(1, 1);
    for (int i = 0; i < cnt; ++i) {
        int u, v;
        tie(u, v) = edge[i];
        g[u].push_back(make_pair(v, i));
        g[v].push_back(make_pair(u, i));
    } 
    dfs(1);
    printf("%d\n", tour.size() -1);
    for (int i = 1; i < (int)tour.size(); i += 2) {
        printf("%d %d\n", tour[i], tour[i-1]);
        printf("%d %d\n", tour[i], tour[i+1]);
    }
    return 0;
}
```

