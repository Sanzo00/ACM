#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 1000 + 5;
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    LL n, d, t;
    cin >> n;
    LL l = 0, r;
    cin >> t;
    r = t;
    for (int i = 1; i < n; ++i) {
        cin >> d;
        if (i & 1) {
            t -= d;
            l = max(l, t);
        }else {
            t += d;
            r = min(r, t);
        }
    }
    cout << max((r - l + 1), 0ll) << "\n";

    return 0;
}
