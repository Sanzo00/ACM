#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 2e5 + 7;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	ans ^= a[i];
    }
    if (ans != 0) {
    	cout << "YES\n";
    	return 0;
    }
    for (int i = 0; i < n; ++i) {
    	if (a[i] < k) continue;
    	int t = ans;
    	t ^= a[i];
    	t ^= a[i] - k;
    	if (t != 0) {
    		cout << "YES\n";
    		return 0;
    	}
    }
    cout << "NO\n";
    return 0;
}
