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

    LL a, b, c;
    cin >> a >> b >> c;
    LL t = 1e18;
    t = min(t, a/3);
    t = min(t, b/2);
    t = min(t, c/2);
    a -= 3 * t;
    b -= 2 * t;
    c -= 2 * t;
    LL ans = 0;
    for (int i = 0; i <= 6; ++i) {
    	LL tmp = 0;
    	int j = i;
    	LL aa = a, bb = b, cc = c;
    	while (1) {
    		if (j == 0 || j == 3 || j == 6) {
    			if (aa == 0) break;
    			aa--;
    		}else if (j == 1 || j == 5) {
    			if (bb == 0) break;
    			bb--;
    		}else{
    			if (cc == 0) break;
    			cc--;
    		}
    		j = (j + 1) % 7;
    		tmp++;
    	}
    	ans = max(ans, tmp);
    }
    ans += t * 7;
    cout << ans << endl;
    return 0;
}