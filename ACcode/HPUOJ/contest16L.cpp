#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 100001;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int fa[maxn];
int find(int x) {
    return (x == fa[x]) ? x : fa[x] = find(fa[x]);
}

int join(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return 0;
    if (fx > fy) swap(fx, fy);
    fa[fy] = fx;
    return 1;
}

struct ac{
    LL u, v, d;
    bool operator < (const ac &t) {
        return d < t.d;
    }
}a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 0, u, v, d; i < m; ++i) {
        cin >> u >> v >> d;
        join(u, v);
    }
    LL ans = 0;
    for (int i = 0; i < s; ++i) {
        cin >> a[i].u >> a[i].v >> a[i].d;
    }

    sort(a, a + s);
    for (int i = 0; i < s; ++i) {
        int u = a[i].u;
        int v = a[i].v;
        LL d = a[i].d;
        int t = join(u, v);
        if (t) ans += d;
    }
    int flag = 1;
    for (int i = 1; i <= n && flag; ++i) {
        if (find(i) != find(1)) flag = 0;
    }
    if (flag) cout << ans << endl;
    else cout << "Concubines can't do it.\n";
    return 0;
}