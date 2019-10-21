#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
using namespace std;
vector<int> g[maxn][10], que[maxn];
int cnt, vis[maxn];
long long ans[maxn];
void add(int u, int v, int d) {
    vector<int> tmp;
    while (d) {
        tmp.push_back(d%10);
        d /= 10;
    }
    reverse(tmp.begin(), tmp.end());
    int l = u, r, len = tmp.size();
    for (int i = 0; i < len; ++i) {
        if (i == len-1) r = v;
        else r = ++cnt;
        g[l][tmp[i]].push_back(r);
        l = r;
    }
    // 反向
    l = v;
    for (int i = 0; i < len; ++i) {
        if (i == len-1) r = u;
        else r = ++cnt;
        g[l][tmp[i]].push_back(r);
        l = r; 
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    cnt = n;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        add(u, v, i);
    }
    que[1].push_back(1);
    vis[1] = 1;
    int now = 1;
    for (int k = 1; k <= now; ++k){
        for (int i = 0; i < 10; ++i) { // small is first
            int flag = 0;
            for (auto u : que[k]) {
                for (auto v : g[u][i]) {
                    if (vis[v]) continue;
                    vis[v] = flag = 1;
                    ans[v] = (ans[u]*10 + i) % mod;
                    que[now+1].push_back(v);
                }
            }
            if (flag) now++;
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}

