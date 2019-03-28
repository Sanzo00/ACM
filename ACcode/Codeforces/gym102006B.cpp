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


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    freopen("hamming.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string l, r;
        cin >> n;
        cin >> l >> r;
        int cnt1 = 0, cnt0 = 0;
        for (int i = 0; i < n; ++i) {
            if (l[i] != r[i]) continue;
            if (l[i] == '0') cnt0++;
            else cnt1++;
        }
        int ans = n - cnt1 - cnt0;
        ans += 2 * min(cnt1, cnt0);
        cout << ans << endl;
    }


    return 0;
}