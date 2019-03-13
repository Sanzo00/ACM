#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define maxn 1005
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
// __int128 read() {	__int128 x = 0, f = 1;	char c = getchar();	while (c < '0' || c > '9') {		if (c == '-') f = -1;		c = getchar();	}	while (c >= '0' && c <= '9') {		x = x * 10 + c - '0';		c = getchar();	}	return x * f;}
// void print(__int128 x) {	if (x < 0) {		putchar('-');		x = -x;	}	if (x > 9)	print(x / 10);	putchar(x % 10 + '0');}
// p1 not equal, p2 equal
int inf = 0x3f3f3f3f;
const LL mod = 1e9 + 9;
LL dp[200][1003], cnt[200][1003];

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL k, b;
    while (cin >> k >> b) {
        mem(cnt, 0);
        mem(dp, 0);
        cnt[1][0]++;
        cnt[1][1%k]++;
        dp[1][1%k]++;
        LL tmp = 1 % k;
        for (int i = 2; i <= b; ++i) {
            tmp = tmp * 2 % k;
            for (int j = 0; j < k; ++j) {
                int pre = (j + k - tmp) % k;
                cnt[i][j] = (cnt[i-1][j] + cnt[i-1][pre]) % mod;
                dp[i][j] = (dp[i-1][j] + cnt[i-1][pre] + dp[i-1][pre] % mod) % mod;
            }
        }
        cout << dp[b][0] << endl;
    }
    
    return 0;
}
