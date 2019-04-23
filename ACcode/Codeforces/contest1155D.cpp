#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    LL n, x;
    cin >> n >> x;
    LL ans = 0;
    vector<LL> a(n+1), b(n+1, 0), c(n+1, 0), d(n+1, 0);
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	b[i] = max(b[i-1], b[i]) + a[i];
    	c[i] = max(c[i], max(c[i-1], b[i-1]) + a[i] * x);
    	d[i] = max(d[i], max(c[i-1], d[i-1]) + a[i]);
    	ans = max(ans, a[i]);
    	ans = max(ans, b[i]);
    	ans = max(ans, c[i]);
    	ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}