#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 1000001;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
int mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int t = sqrt(n);
        if (n == 0 || t * t == n) {
            puts("infty");
            continue;
        }
        if (n % 4) {
            puts("0 0");
            continue;
        }
        n /= 4;
        LL ans = 0, sum = 0;
        for (int i = 1; i*i <= n; ++i) {
            if (n % i == 0) {
                ans = ((1ll * i * (n/i)  * (i+n/i) % mod) + ans) % mod;
                sum++;
            }
        }
        printf("%lld %lld\n", sum, ans);
    }
    return 0;
}