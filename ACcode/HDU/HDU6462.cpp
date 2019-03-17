#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 500005;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

const LL mod = 192600817;


LL f[maxn];

int main() {
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    f[1] = f[2] = 1;
    for (int i = 3; i < maxn; ++i) {
        f[i] = (f[i-1] + f[i-2]) % mod;
    }
    for (int i = 1; i < maxn; ++i) {
        f[i] = (f[i] * f[i]) % mod;
        f[i] = (f[i] + f[i-1]) % mod;
    }

    int n;
    while (scanf("%d", &n) != EOF) {
        int a, b, c, d;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            a *= 4;
            c *= 4;
            a += b;
            c += d;
            if (a > c) swap(a, c);
            c++;
            printf("%lld\n", (f[c] - f[a] + mod) % mod);
        }
    }
    
    return 0;
}