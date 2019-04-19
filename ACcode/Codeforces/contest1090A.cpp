#include <bits/stdc++.h>
#define LL long long
#define P pair<LL, LL>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 2e5 + 7;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n;
    vector<P> a(n);
    int level = 0;
    for (int i = 0; i < n; ++i) {
    	cin >> m;
    	a[i].first = m;
    	int tmp = 0;
    	for (int j = 0, d; j < m; ++j) {
    		cin >> d;
    		tmp = max(d, tmp);
    	}
    	a[i].second = tmp;
    	level = max(level, tmp);
    }
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
    	ans += a[i].first * (level - a[i].second);
    }
    cout << ans << endl;
    return 0;
}