#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	
    int T;
    cin >> T;
    vector<int> a(7);
    while (T--) {
    	for (int i = 1; i <= 6; ++i) {
    		cin >> a[i];
    	}
    	LL ans = a[6];

    	ans += a[5];
    	a[1] = max(0, a[1] - a[5]);

    	ans += a[4];
    	if (a[4] > a[2]) {
    		a[4] -= a[2];
    		a[2] = 0;
    		a[1] = max(0, a[1] - 2*a[4]);
    	}else {
    		a[2] -= a[4];
    	}
    	ans += a[3] / 2;
    	a[3] %= 2;
    	if (a[3]) {
    		ans++;
    		if (a[2] && a[1]) a[2]--, a[1]--;
    		else if (a[2] && !a[1]) a[2]--;
    		else if (!a[2] && a[1]) a[1] = max(0, a[1] - 3);
    	}
    	int t = a[1] + a[2] * 2;
    	ans += t / 6;
    	if (t % 6) ans++;
    	cout << ans << endl;
    }

    return 0;
}
