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
int a[1003];
int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0, l, r; i < n; ++i) {
        cin >> l >> r;
        a[l]++;
        a[r+1]--;
    }
    int ans = -1;
    int now = a[0];
    if (now == 0) ans = 0;
    for (int i = 1; i <= n; ++i) {
        now += a[i];
        if (now == i) ans = i;
    }
    cout << ans << endl;
    
    return 0;
}
