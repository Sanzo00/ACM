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
LL ans, tmp;
void solve(LL x, LL a, LL b) {
	if (a % x != b % x)  return;
	LL add = x - a%x;
	a += add;
	b += add;
	if (a * b / __gcd(a, b) < tmp) {
		tmp = a * b / __gcd(a, b);
		ans = add;
	}
	return;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    LL a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    tmp = a * b / __gcd(a, b);
    ans = 0;
    LL len = b - a;
    for (LL i = 1; i <= sqrt(len); ++i) {
    	if ((b-a) % i) continue;
    	solve(i, a, b);
    	solve(len/i, a, b);
    }
    cout << ans << endl;
    return 0;
}