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
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 1e9;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i <= 100; ++i) {
    	set<int> st;
    	int tmp = 0;
    	for (int j = 0; j < n; ++j) {
    		int t = abs(i - a[j]);
    		if (t == 0) continue;
    		tmp = max(tmp, t);
    		st.insert(t);
    	}
    	if (st.size() <= 1) {
    		ans = min(ans, tmp);
    	}
    }
    if (ans == 1e9) ans = -1;
    cout << ans << endl;

    return 0;
}