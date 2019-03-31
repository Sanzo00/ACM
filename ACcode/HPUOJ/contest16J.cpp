#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 105;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
int mod = 1e9 + 7;
LL f[1000006];
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    int T;
    cin >> T;
    f[1] = f[2] = 1;
    for (int i = 3; i <= 1000000; ++i) {
        f[i] = (f[i-1] * 2 % mod) + (f[i-2] / 2 % mod);
        f[i] %= mod;
    }

    while (T--) {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }

    return 0;
}