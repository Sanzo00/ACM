#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    LL h, m;
    while (cin >> h >> m) {
    	LL r = h * m;
    	LL l = (m + m - min(h, m) + 1) * min(h, m) / 2;
    	LL t = __gcd(r, l);
    	r /= t;
    	l /= t;
    	cout << l << "/" << r << endl;
    }

    return 0;
}
