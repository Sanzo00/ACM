#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, d;
		cin >> n >> k >> d;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		set<int> st;
		map<int,int> mp;
		int ans = 1e9;
		int t = n - d;
		if (t < 0) t = 0;
		for (int i = 0; i < d; ++i) st.insert(a[i]), mp[a[i]]++;
		ans = st.size();
		// cout << ans << endl;
		for (int i = d; i < n; ++i) {
			mp[a[i-d]]--;
			if (mp[a[i-d]] == 0) st.erase(a[i-d]);
			mp[a[i]]++;
			st.insert(a[i]);
			ans = min(ans, (int)st.size());
		}
		cout << ans << endl;
	}
	return 0;
}
