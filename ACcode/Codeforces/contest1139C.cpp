#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 100005;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int mod = 1e9 + 7;
int sum;

int quick (LL x, int y) {
    LL ans = 1;
    while (y) {
        if (y & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

vector<int> g[maxn];
int vis[maxn];

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = 1;
    sum++;
    for (int it : g[x]) dfs(it);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   

    int n, k;
    cin >> n >> k;
    for (int i = 0, u, v, d; i < n-1; ++i) {
        cin >> u >> v >> d;
        if (d) continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = quick(n, k);

    for (int i = 1; i <= n; ++i) {
        sum = 0;
        dfs(i);
        ans = (ans - quick(sum, k) + mod) % mod;
    }
    cout << ans << endl;


    return 0;
}