#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 1044373;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;


const LL mod = 123456789;

// 定义矩阵 重载*
struct ac{
    LL a[6][6];
    ac operator * (ac b) {
        ac t;
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                t.a[i][j] = 0;
                for (int k = 0; k < 6; ++k) {
                    t.a[i][j] = (t.a[i][j] + (a[i][k] * b.a[k][j] % mod)) % mod;
                }
            }
        }
        return t;
    }
}g, m;
// 矩阵快速幂
ac quick(ac tmp, LL x) {
    ac t;
    mem(t.a, 0);
    for (int i = 0; i < 6; ++i) t.a[i][i] = 1;
    while (x) {
        if (x & 1) t = t * tmp;
        tmp = tmp * tmp;
        x >>= 1; 
    }
    return t;
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    scanf("%d", &T);
    g.a[0][1] = 1;
    g.a[1][0] = 2;
    g.a[1][2] = g.a[1][1] = 1;
    g.a[1][3] = g.a[1][4] = 3;
    g.a[1][5] = g.a[2][2] = 1;
    g.a[2][3] = g.a[2][4] = 3;
    g.a[2][5] = g.a[3][3] = 1;
    g.a[3][4] = 2;
    g.a[3][5] = g.a[4][4] = g.a[4][5] = g.a[5][5] = 1;

    m.a[0][0] = 1;
    m.a[1][0] = 2;
    m.a[2][0] = 8;
    m.a[3][0] = 4;
    m.a[4][0] = 2;
    m.a[5][0] = 1;

    while (T--) {
        LL n;
        scanf("%lld", &n);
        if (n == 1 || n == 2) {
            printf("1\n");
            continue;
        }
        ac t = quick(g, n-2);
        ac ans = t * m;      

        printf("%lld\n", ans.a[1][0]);
    }

    return 0;
}
