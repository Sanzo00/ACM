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
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    int ans = 1;
    int tmp = 1;
    for (int i = 1; i < n; ++i) {
    	if (a[i] != a[i-1]) tmp++;
    	else {
    		ans = max(tmp, ans);
    		tmp = 1;
    	}
    }
    ans = max(tmp, ans);
    cout << ans << endl;

    return 0;
}