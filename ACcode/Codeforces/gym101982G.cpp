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

struct ac{
    int x, y;
};
double solve(ac a, ac b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ac a, b, c;
    while (scanf("%d %d %d %d %d %d", &c.x, &c.y, &a.x, &a.y, &b.x, &b.y) != EOF) {
        double ans;
        if (c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y)) {
            ans = min(abs(c.x - a.x), abs(c.x - b.x));
            
        }else if (c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x)) {
            ans = min(abs(c.y - a.y), abs(c.y - b.y));
            
        }else {
            ans = min(solve(c, a), solve(c, b));
            ans = min(ans, solve(c, {a.x, b.y}));
            ans = min(ans, solve(c, {a.y, b.x}));
        }
        printf("%.3lf\n", ans);
    }
    
    return 0;
}
