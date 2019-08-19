#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	long long ans = 0;
	int tmp = 1;
	for (auto &i : a) {
		if (fabs(i) == 1) {
			tmp *= i;
			continue;
		}
		if (fabs(i-1) > fabs(i+1)) ans += fabs(i+1), i = -1;
		else ans += fabs(i-1), i = 1;
		tmp *= i;
	}
	if (tmp == -1) ans += 2;
	cout << ans << endl; 
	return 0;
}