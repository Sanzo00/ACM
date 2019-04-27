#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    int n, m;
    while (T--) {
    	cin >> n >> m;
	    vector<int> a(m), b;
	    for (int i = 0; i < m; ++i) {
	    	cin >> a[i];
	    }
	    sort(a.begin(), a.end());
	    b.push_back(abs(a[0] + n - a[m-1]));
	    for (int i = 1; i < m; ++i) {
	    	b.push_back(a[i] - a[i-1]);
	    }
	    sort(b.begin(), b.end());
	    int l, r = n;
	    for (int i = 1; i <= n; ++i) {
	    	r = n;
	    	if (i == 1) {
	    		l = m;
	    	}else {
	    		auto p = lower_bound(b.begin(), b.end(), i); 
	    		l = b.end() - p;
	    	}
	    	if (l == 0) cout << 0 << endl;
	    	else {
	    		int t = __gcd(l, r);
	    		l /= t;
	    		r /= t;
	    		cout << l << "/" << r << endl;
	    	}
	    }
    }
    return 0;
}
