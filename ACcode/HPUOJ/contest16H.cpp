#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct ac{
    int a, b, c, d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    ac x, y;
    cin >> x.a >> x.b >> x.c >> x.d;
    cin >> y.a >> y.b >> y.c >> y.d;
    if (x.a > y.a) swap(x, y);
    int ans = 0;
    ans = (x.c - x.a) * (x.d - x.b);
    ans += (y.c - y.a) * (y.d - y.b);
    
    int l;
    if (y.a >= x.a && y.c <= x.c) l = y.c - y.a;
    if (y.a > x.a && y.c > x.c && y.a < x.c) l = x.c - y.a;
    if (y.a < x.a && y.c > x.a && y.c < x.c) l = y.c - x.a;
    if (y.a <= x.a && y.c >= x.c) l = x.c - x.a;
    if (y.c <= x.a || y.a >= x.c) l = 0;

    int r;
    if (y.b >= x.d || y.d <= x.b) r = 0;
    if (y.d >= x.d && y.b <= x.b) r = x.d - x.b;
    if (y.d <= x.d && y.b >= x.b) r = y.d - y.b;
    if (y.d > x.b && y.b < x.b && y.d < x.d) r = y.d - x.b;
    if (y.b > x.b && y.d > x.d && y.b < x.d) r = x.d - y.b;
    ans -= l * r;
    cout << ans << endl;

    return 0;
}