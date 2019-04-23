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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<LL>a(n), b(m);
    map<LL, int> mp;
    for (int i = 0; i < n; ++i) cin >> a[i];    	
    for (int i = 0; i < m; ++i) {
    	cin >> b[i];
    	mp[b[i]] = i+1;
    }
    LL tmp = a[1] - a[0];
    for (int i = 2; i < n; ++i) {
    	tmp = __gcd(tmp, a[i] - a[i-1]);
    }
    for (int i = 0; i < m; ++i) {
    	if (tmp % b[i] == 0) {
    		cout << "YES\n";
    		cout << a[0] << " " << mp[b[i]] << endl;
    		return 0;
    	}
    }
    cout << "NO\n";

    return 0;
}