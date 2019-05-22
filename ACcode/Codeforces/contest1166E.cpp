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
set<int> g[55];
int main() {
    
    int n, m, d, x;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> d;
        for (int j = 0; j < d; ++j) {
            cin >> x;
            g[i].insert(x);
        }
    }
    int flag = 0;
    for (int i = 0; i < n && !flag; ++i) {
        for (int j = i + 1; j < n && !flag; ++j) {
            int tmp = 0;
            for (auto s1 : g[j]) {
                if (g[i].find(s1) != g[i].end()) {
                    tmp = 1;
                    break;
                }
            }
            if (tmp == 0) {
                flag = 1;
                break;
            }
        }
    }
    string ans;
    if (flag) ans = "impossible";
    else ans = "possible";
    cout << ans << endl;
    
    return 0;
}