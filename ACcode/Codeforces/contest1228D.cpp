#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
mt19937 rnd(time(0));
long long f[maxn], a[maxn];
map<long long, vector<int>> mp;
int ans[maxn], in[maxn];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) f[i] = rnd();
    fill(a, a+maxn, 0);
    mp.clear();
    for (int i = 0,u,v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        a[u] ^= f[v];
        a[v] ^= f[u];
        in[u]++;
        in[v]++;
    }
    int flag = 1;
    for (int i = 1; i <= n; ++i) {
        mp[a[i]].push_back(i);
        if (in[i] == 0) flag = 0;
    }
    if (mp.size() != 3) flag = 0;
    int cnt = 0;
    for (auto i : mp) {
        ++cnt;
        for (auto j : i.second) ans[j] = cnt;
    }
    if (!flag) puts("-1");
    else {
        for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    }
    return 0;
}
