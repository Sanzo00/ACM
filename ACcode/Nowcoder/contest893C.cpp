#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 3e2 + 1;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
    	int l, r;
    	cin >> l >> r;
    	int low = (l / 192) * 192 + 1;
    	while(low < l) low += 192;
    	int high = (r / 192) * 192 + 1;
    	while (high > r) high -= 192;
    	if (low > r || high < l) {
    		cout << 0 << endl;
    	}else {
    		LL ans = 1ll * (low + high) * ((high - low) / 192 + 1) / 2;
    		cout << ans << endl;
    	}
    }

    return 0;
}