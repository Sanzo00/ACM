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
const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;

int low[maxn], dfn[maxn], now, root = 1;
vector<int> g[maxn];
set<int> ans;
void init() {
    now = 0;
    mem(dfn, 0);
    mem(low, 0);
}
void addedge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}
void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++now;
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
    int n, x, y;
    while (scanf("%d", &n), n) {
        init();
        ans.clear();
        for (int i = 0; i <= n; ++i) g[i].clear();
        while (scanf("%d", &x), x) {
            while (getchar() != '\n') {
                scanf("%d", &y);
                addedge(x, y);
            }
        } 
        tarjan(1, 0);
        cout << ans.size() << endl;
    }
    return 0;
}