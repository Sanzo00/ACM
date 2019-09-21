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