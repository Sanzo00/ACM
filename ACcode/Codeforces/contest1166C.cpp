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

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &v : a) {
        cin >> v;
        v = abs(v);
    }
    sort(a.begin(), a.end());
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        int it = upper_bound(a.begin(), a.end(), a[i]*2) - a.begin();
        it = it - i - 1;
        ans += it;
    }
    cout << ans << endl;
    
    return 0;
}