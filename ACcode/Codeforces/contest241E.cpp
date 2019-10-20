#include <bits/stdc++.h>
const int maxn = 5e3 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int ans[maxn], cnt[maxn], dis[maxn], vis[maxn];
int n, m;
vector<int> g1[maxn], g2[maxn];
vector<pair<int,int> > g[maxn];
vector<pair<int,int> > edge;
void dfs1(int u) {
    cnt[u]++;
    for (auto v : g1[u]) {
        if (cnt[v]) continue;
        dfs1(v);
    }
}
void dfs2(int u) {
    cnt[u] += 2;
    for (auto v : g2[u]) {
        if (cnt[v] & 2) continue;
        dfs2(v);
    }
}

void spfa() {
    fill(dis, dis+maxn, inf);
    fill(vis, vis+maxn, 0);
    fill(cnt, cnt+maxn, 0);
    queue<int> que;
    que.push(1);
    dis[1] = 0;
    vis[1] = 1;
    cnt[1] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = 0;
        for (auto it : g[u]) {
            int v, c;
            tie(v, c) = it;
            if (dis[v] > dis[u] + c) {
                dis[v] = dis[u] + c;
                if (vis[v]) continue;
                vis[v] = 1;
                que.push(v);
                if (++cnt[v] > n) {
                    cout << "No\n";
                    exit(0);
                }
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edge.push_back(make_pair(u, v));
        g1[u].push_back(v);
        g2[v].push_back(u);
    }
    fill(cnt, cnt+maxn, 0);
    dfs1(1);
    dfs2(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        tie(u, v) = edge[i];
        if (cnt[u] != 3 || cnt[v] != 3) continue;
        g[u].push_back(make_pair(v, 2));
        g[v].push_back(make_pair(u, -1));
    }
    spfa();
    cout << "Yes\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        tie(u, v) = edge[i];
        ans[i] = dis[v] - dis[u];
        if (ans[i] != 1 && ans[i] != 2) ans[i] = 1;
        cout << ans[i] << endl;
    }
    return 0;
}
