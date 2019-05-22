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
LL num[55], R[55], a, b, m;
void init() {
    for (LL i = 0; i <= 50; ++i) {
        num[i] = 1ll << i;
    }
}
int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> m;
        if (a == b) {
            cout << 1 << " " << a << endl;
            continue;
        }
        int cnt = -1;
        for (int i = 2; i <= 50; ++i) {
            LL l = b / num[i - 2];
            LL r = b / num[i - 2];
            if (l >= a + 1 && r <= a + m && b <= num[i-2] * (a + m)) {
                cnt = i;
                break;
            }
        }
        if (cnt == -1) {
            cout << cnt << endl;
            continue;
        }
        LL tmp = b, tot;
        tmp -= num[cnt-2] * a;
        tmp -= num[cnt-2];
        for (int i = 1; i < cnt; ++i) {
            R[i] = 1;
            if (i < cnt-1 && tmp > 0 && R[i] < m && num[cnt-2-i] <= tmp) {
                tot = tmp / num[cnt-2-i];
                tot = min(tot, m-1);
                tmp -= num[cnt-2-i] * tot;
                R[i] += tot;
            }else if (i == cnt-1) {
                R[i] += tmp;
            }
        }
        vector<LL> ans;
        ans.push_back(cnt);
        ans.push_back(a);
        ans.push_back(a+R[1]);
        for (int i = 3; i <= cnt; ++i) {
            ans.push_back(ans.back() * 2 + R[i-1] - R[i-2]);
        }
        for (auto it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}