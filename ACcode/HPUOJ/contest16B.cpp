#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 1001;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int mod = 1e9 + 7;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    int T;
    cin >> T;
    map<int, char> mp;
    mp[10] = 'a';
    mp[11] = 'b';
    mp[12] = 'c';
    mp[13] = 'd';
    mp[14] = 'e';
    mp[15] = 'f';
    while (T--) {
        string s;
        cin >> s;
        string t;
        int len = s.size();
        int last = len % 4;
        for (int i = 0; last && i < 4 - last; ++i) {
            s = "0" + s;
        }
        len = s.size();
        int tmp = 0;
        int cnt = 0;
        for (int i = 0; i < len; ++i) {
            ++tmp;
            cnt = cnt * 2 + s[i] - '0';
            if (tmp % 4 == 0) {
                // cout << tmp << endl;
                if (cnt <= 9) t += '0' + cnt;
                else t += mp[cnt];
                cnt = 0;
            }
        }
        cout << t << endl;
    }

    return 0;
}