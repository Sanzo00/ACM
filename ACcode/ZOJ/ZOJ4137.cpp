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
LL solve(int x) {
	LL ans = 1;
	while (x) {
		ans = ans * (x % 10) % mod;
		x /= 10;
	}
	return ans;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T, l, r;
    cin >> T;
    while (T--) {
    	cin >> l >> r;
    	if (r - l >= 9) {
    		cout << 0 << endl;
    		continue;
    	}
    	LL ans = 1;
    	for (int i = l; i <= r && ans; ++i) {
    		ans = ans * solve(i) % mod;
    	}
    	cout << ans << endl;
    }
    return 0;
}
