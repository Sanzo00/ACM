#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 2e2 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
void solve(string &s, int cnt, int n, int m, char c) {
    for (int i = 0; i < cnt; ++i) {
        s += c;
    }
    if (c == 'U') c = 'R';
    else c = 'U';
    for (int i = 0; i < n; ++i) {
        s += c;
    }
    if (c == 'U') c = 'R';
    else c = 'U';
    for (int i = cnt; i < m; ++i) {
        s += c;
    }
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T, n, m, flag, cnt;
    string s, ans;
    cin >> T;
    while (T--) {
        cin >> n >> m >> s;
        ans.clear();
        int len = n + m;
        if (s[0] == s[len-1]) {
            flag = 0;
            cnt = 0;
            if (s[0] == 'U') {
                for (int i = 1; i < len; ++i) {
                    if (s[i] == 'R') cnt++;
                    if (s[i] == 'R' && s[i-1] == 'R') {
                        flag = 1;
                        break;
                    }
                }
                cnt--;
                if (flag) solve(ans, cnt, n, m, 'R');
            }else {
                for (int i = 1; i < len; ++i) {
                    if (s[i] == 'U') cnt++;
                    if (s[i] == 'U' && s[i-1] == 'U') {
                        flag = 1;
                        break;
                    }
                }
                cnt--;
                if (flag) solve(ans, cnt, m, n, 'U');
            }
        }else {
            if (s[0] == 'U' && s[len-1] == 'R') {
                for (int i = 0; i < m; ++i) ans += 'R';
                for (int i = 0; i < n; ++i) ans += 'U';
            }else if (s[0] == 'R' && s[len-1] == 'U'){
                for (int i = 0; i < n; ++i) ans += 'U';
                for (int i = 0; i < m; ++i) ans += 'R';
            }
        }
        if (ans.empty()) ans = "impossible";
        cout << ans << endl;
    }

    return 0;
}