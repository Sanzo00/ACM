#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 1e7 + 2;
vector<vector<int>> b(maxn);
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	b[a[i]].push_back(i);
    }
    int l, r;
    LL ans = 1e18;
    for (LL i = 1; i < maxn; ++i) {
    	vector<int> tmp;
    	for (LL j = i; j < maxn; j += i) {
    		int len = b[j].size();
    		for (int k = 0; k < min(len, 2); ++k) {
    			tmp.push_back(b[j][k]);
    			if (tmp.size() == 2) break;
    		}
    		if (tmp.size() == 2) break;
    	}
    	if (tmp.size() != 2) continue;
    	LL num = 1ll * a[tmp[0]] * a[tmp[1]] / __gcd(a[tmp[0]], a[tmp[1]]);
    	if (num < ans) {
    		ans = num;
    		l = tmp[0];
    		r = tmp[1];
    	}
    }
    l++; r++;
    if (l > r) swap(l, r);
    cout << l << " " << r << endl;
    return 0;
}