#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 5e2 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);	
    double l, r, L, R;
    scanf("%lf%lf%lf%lf", &l, &r, &L, &R);
    double q = (L + R) / 2;
    double x = (q + l) / 2;
    if (x > r || x < l) {
    	if (abs(x - l) < abs(x - r)) x = l;
    	else x = r;
    }
    double ans = -x*x + (q+l)*x - q*l;
    ans /= (r - l);
    ans = max(0.0, ans);
    printf("%.4lf\n", ans);
    return 0;
}
