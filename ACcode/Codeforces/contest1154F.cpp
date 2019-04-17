#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n+1), sum(n+1), dp(n+1);
    vector<P> all;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    a[0] = 0;
    for (int i = 0; i < m; ++i) {
    	int l, r;
    	cin >> l >> r;
    	all.push_back(make_pair(l, r));
    }

    sort(a.begin(), a.end());
    for (int i = 1; i <= n; ++i) {
    	sum[i] = sum[i-1] + a[i]; 
    }
    for (int i = 1; i <= k; ++i) {
    	dp[i] = dp[i-1] + a[i]; 
    	for (auto it : all) {
    		int l = it.first;
    		int r = it.second;
    		if (l > i) continue;
    		dp[i] = min(dp[i], dp[i-l] + sum[i] - sum[i-l+r]);
    	}
    }
    cout << dp[k] << endl;

    return 0;
}
