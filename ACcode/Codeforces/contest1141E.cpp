#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 200005;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

LL dp[maxn], sum[maxn];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, h;

    while (cin >> h >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> dp[i];
            sum[i] = dp[i] + sum[i-1];
        }

        LL ans = 1e18;

        for (LL i = 1; i <= n; ++i) {

            LL last = h + sum[i];

            if (last <= 0) {
                ans = min(ans, i);
            }else {

                if (sum[n] >= 0) continue;

                LL cnt = last / (abs(sum[n]));
                if (last % abs(sum[n])) cnt++;
                ans = min(ans, cnt * n + i);
            }
        }

        ans = (ans == 1e18) ? -1 : ans;
        cout << ans << endl;
    }


    return 0;
}
