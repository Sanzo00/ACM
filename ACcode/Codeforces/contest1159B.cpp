#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 3e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int a[maxn], l[maxn], r[maxn];	
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    vector<P> b;
    for (int i = n; i >= 1; --i) {
    	if (b.empty() || a[i] > b.back().first) b.push_back(make_pair(a[i], i));
    	auto p = lower_bound(b.begin(), b.end(), make_pair(a[i], -1));
    	r[i] = p->second;
    }
    b.clear();
    for (int i = 1; i <= n; ++i) {
    	if (b.empty() || a[i] > b.back().first) b.push_back(make_pair(a[i], i));
    	auto p = lower_bound(b.begin(), b.end(), make_pair(a[i], -1));
    	l[i] = p->second;
    }
    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
    	int tmp = l[i];
    	if (tmp != i) {
    		ans = min(ans, a[i] / (i - tmp));
    	}
    	tmp = r[i];
    	if (tmp != i) {
    		ans = min(ans, a[i] / (tmp - i));
    	}
    }
    cout << ans << endl;

    return 0;
}