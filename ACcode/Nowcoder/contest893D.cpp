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
    scanf("%d", &T);
    while (T--) {
    	int n, pos, Max = -1;
    	scanf("%d", &n);
    	vector<LL>a(n);
    	LL ans = 0;
    	for (int i = 0; i < n; ++i) {
    		scanf("%lld", &a[i]);
    		if (a[i] > Max) {
    			Max = a[i];
    			pos = i;
    		}
    		ans += a[i];
    	}
    	ans -= a[pos];
    	printf("%lld\n", ans);
    }
    return 0;
}