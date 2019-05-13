#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        LL ans = 0;
        int len = s.size();
        for (LL i = 2; i <= 10; ++i) {
            LL tmp = 0;
            for (int j = 0; j < len; ++j) {
                tmp = tmp * i + s[j] - '0';
            }
            ans += tmp;
        }
        cout << ans << endl;
    }

    return 0;
}