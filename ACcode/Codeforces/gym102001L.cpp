#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 100005;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

LL K;
string s;

LL val() {
    LL x = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        x = x * 2 + s[i] - '0';
    }
    return x;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    
    cin >> K >> s;
    int ans = 0;
    while (val() > K) {
        ans++;
        int len = s.size();
        int flag = 0;
        for (int i = 1; i < len; ++i) {
            if (s[i] == '1') {
                flag = 1;
                s.erase(i, 1);
                break;
            }
        }
        if (flag) continue;
        s.pop_back();
    }
    cout << ans << endl;

    return 0;
}