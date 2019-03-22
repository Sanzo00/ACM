#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 200005;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   

    int n;
    string s;
    cin >> n >> s;
    LL ans = 0;
    
    for (LL i = 0; i < n; ++i) {
        if ((s[i] - '0') % 2 == 0) ans += i+1;
    }
    cout << ans << endl;

    return 0;
}