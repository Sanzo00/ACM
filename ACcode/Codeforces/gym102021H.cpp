#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 3e6;
using namespace std;
LL quick(LL a, int b) {
    LL ans = 1;
    while (b) {
        if (b&1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
int solve(LL x, int k) {
    int t = 1;
    LL tmp = 1;
    while (x >= tmp) {
        x -= tmp;
        t++;
        if (tmp <= 0 || x <= tmp) break;
        tmp = quick(t, k);
        
    }
    if (x) return 0;
    return t - 1;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    LL n;
    cin >> n;
    for (int i = 2; i <= 60; ++i) {
        int d = solve(n, i);
        if (!d) continue;
        cout << i+1 << " " << d << endl;
        return 0;
    }
    cout << "impossible\n";
    
    return 0;
}
