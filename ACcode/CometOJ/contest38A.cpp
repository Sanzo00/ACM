#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<LL> a(n);
    vector<LL> b;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
    	for (int j = i+1; j < n; ++j) {
    		b.push_back(a[i] + a[j]);
    	}
    }
    sort(b.begin(), b.end());
    LL ans = 0;
    int len = b.size();
    for (int i = len-1; i >= 0 && k; --i, --k) {
    	ans += b[i];
    }
    cout << ans << endl;
    return 0;
}