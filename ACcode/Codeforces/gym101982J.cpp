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


int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, s;
    while (cin >> n >> s) {
    
        int MAX = 0;
        for (int i = 0, d; i < n; ++i) {
            cin >> d;
            MAX = max(MAX, d);
        }
        MAX *= s;
        int ans = MAX / 1000;
        if (ans * 1000 < MAX) ans++;
        cout << ans << endl;
            
    }

    return 0;
}
