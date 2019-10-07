#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int l, r;
	cin >> l >> r;
	set<int> st;
	for (int i = l; i <= r; ++i) {
		int t = i;
		int cnt = 0;
		st.clear();
		while (t) {
			st.insert(t%10);
			t /= 10;
			cnt++;
		}
		if (cnt == st.size()) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
