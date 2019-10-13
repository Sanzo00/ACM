---

CF - 741(C. Arpa’s overnight party and Mehrdad’s silent entering)  二分图构造

---

[题目链接](http://codeforces.com/contest/741/problem/C)

#### 题意

有N对情侣,每个人都吃一种饭,给出情侣的座位编号.有以下两个要求:

1. 情侣之间不能吃相同的饭
2. 座位号连续的三个人不能吃同一种饭

问是否存在满足的解.

#### 思路

构造二分图

1. 对应情侣的座位建边,保证情侣之间不吃一种饭
2. [2*i-1, 2*i]建边,保证座位号相邻的3个人不全吃一种饭



```cpp
#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
vector<int> g[maxn];
void add(int u, int v) {
    g[u].push_back(v); 
    g[v].push_back(u);
}
int color[maxn], flag;
void dfs(int u, int col) {
    color[u] = col;
    for (int i = 0; i < (int)g[u].size(); ++i) {
        int v = g[u][i];
        if (color[v] == -1) dfs(v, col^1);
        else if (color[v] == col) flag = -1;
    }
}
vector<pair<int,int>> all;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    scanf("%d", &n);
    for (int i = 1, u, v; i <= n; ++i) {
        add(i*2-1, i*2);
        scanf("%d %d", &u, &v);
        all.push_back(make_pair(u, v));
        add(u, v);
    }
    fill(color, color+maxn, -1);
    flag = 1;
    for (int i = 1; i <= n*2; ++i) {
        if (color[i] == -1) dfs(i, 0);
    }
    if (flag == -1) puts("-1");
    else {
        for (auto it : all) {
            printf("%d %d\n", color[it.first]+1, color[it.second]+1);
        }
    }
    return 0;
}
```



