#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int L[maxn], R[maxn];
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s, t;
	cin >> s >> t;
	int lens = s.size();
	int lent = t.size();
	int i = 0, j = 0;
	while (j < lent && i < lens) {
		if (s[i] == t[j]) {
			L[j++] = i;
		}
		i++;
	}
	i = lens-1, j = lent-1;
	while (i >= 0 && j >= 0) {
		if (s[i] == t[j]) {
			R[j] = i;
			--j;
		}
		--i;
	}
	int ans = max(R[0], lens - L[lent-1] - 1);
	for (int i = 1; i < lent; ++i) {
		ans = max(ans, R[i] - L[i-1] - 1);
	}
	cout << ans << endl;
	return 0;
}