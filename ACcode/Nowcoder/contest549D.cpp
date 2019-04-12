#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 100000;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}    
	sort(a.begin(), a.end());
	int ans = 0;
	int cnt = 0;
	for (int i = n-1; i >= 0; --i) {
		if ((ans | a[i]) > ans) {
			ans |= a[i];
			cnt++;
		}
		if (cnt == n-1) break;
	}
	cout << ans << endl;
    return 0;
}