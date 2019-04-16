#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 3e2 + 7;

LL solve(LL a, LL x) {
	LL t = x / a;
	if (t == 0) return 0;
	LL tmp = min(t, a);
	LL sum = tmp * (tmp+1) / 2 + a * (t - tmp);
	LL r = t * a + min(a, t) - 1;
	sum -= max(r - x, 0ll);
	return sum;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
    	LL a, l, r;
    	scanf("%lld%lld%lld", &a, &l, &r);
    	LL ans = solve(a, r) - solve(a, l-1);
    	printf("%lld\n", ans);
    }
    
    return 0;
}