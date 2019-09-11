#include <bits/stdc++.h>
const int maxn = 3e6 + 5e5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
using namespace std;
struct Trie{
    int nex[maxn][2], cnt[maxn], end[maxn];
    int p, root;
    int newnode() {
        memset(nex[p], 0, sizeof(nex[p]));
        cnt[p] = end[p] = 0;
        return p++;
    }
    void init() {
        p = 0;
        root = newnode();
    }
    void add(int x) {
        int now = root;
        for (int i = 30; i >= 0; --i) {
            int t = (x >> i) & 1;
            if (nex[now][t] == 0) nex[now][t] = newnode();
            now = nex[now][t];
            cnt[now]++;
        }
        end[now] = 1;
    }
}L, R;
long long ans;
int a[maxn], b[maxn];
void dfs(int n1, int n2, int x) {
    int t = min(L.cnt[n1], R.cnt[n2]);
    L.cnt[n1] -= t;
    R.cnt[n2] -= t;
    if (L.end[n1]) {
        ans += 1ll * x * t;
        return;
    } 
    int l0 = L.nex[n1][0];
    int l1 = L.nex[n1][1];
    int r0 = R.nex[n2][0];
    int r1 = R.nex[n2][1];
    if (L.cnt[l0] && R.cnt[r1]) dfs(l0, r1, x<<1|1);
    if (L.cnt[l1] && R.cnt[r0]) dfs(l1, r0, x<<1|1);
    if (L.cnt[l0] && R.cnt[r0]) dfs(l0, r0, x<<1);
    if (L.cnt[l1] && R.cnt[r1]) dfs(l1, r1, x<<1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        L.init(), R.init();
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), L.add(a[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &b[i]), R.add(b[i]);
        ans = 0;
        dfs(L.root, R.root, 0);
        printf("%lld\n", ans);
    }
    return 0;
}
