#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 105;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    freopen("hello.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int flag = 1;
        int tmp;
        vector<int> v(12);
        cin >> v[0];
        tmp = v[0];

        for (int i = 1; i < 4; ++i) {
            cin >> v[i];
            if (v[i] - v[i-1] <= 0) flag = 0;
            tmp = max(tmp, v[i]);
        }
        for (int i = 4; i < 12; ++i) {
            cin >> v[i];
            if (v[i] <= tmp) flag = 0;
        }
        string ans = "no";
        if (flag) ans = "yes";
        cout << ans << endl;
    }


    return 0;
}