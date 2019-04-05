#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 1000 + 5;
using namespace std;

int judge(LL x) {
    if (x == 1) return 0;
    if (x == 2 || x == 3) return 1;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return 0;
    }
    return 1;
}
LL solve(string s) {
    LL t = 0;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        if (s[i] == '.') continue;
        t = t * 10 + s[i] - '0';
    }
    return t;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;
        LL l = solve(a);
        LL r = solve(b);
        int d1 = 0, d2 = 0;
        if ((int)a.find('.') != -1) {
            for (int i = a.size()-1; i >= 0; --i) {
                if (a[i] == '.') break;
                else d1++;
            }
        }
        if ((int)b.find('.') != -1) {
            for (int i = b.size()-1; i >= 0; --i) {
                if (b[i] == '.') break;
                else d2++;
            }
        }
        for (int i = 0; i < 5-d1; ++i) l *= 10;
        for (int i = 0; i < 5-d2; ++i) r *= 10;        
        LL t = __gcd(l, r);
        l /= t;
        r /= t;
        if (l == r) cout << "2 2\n";
        else if (judge(l) && judge(r)) cout << l << " " << r << endl;
        else cout << "impossible\n";
    }
    return 0;
}
