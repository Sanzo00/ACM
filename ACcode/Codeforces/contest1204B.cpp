#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, l, r;
	cin >> n >> l >> r;
	long long sum1 = (1ll << l) - 1 + n - l;
	long long sum2 = (1ll << r) - 1 + 1ll * (1ll << (r-1)) * (n-r);
	cout << sum1 << " " << sum2 << endl; 
	return 0;
}