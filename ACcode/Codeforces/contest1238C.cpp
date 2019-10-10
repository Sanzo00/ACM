#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
using namespace std;
int vis[maxn];
int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int h, n;
		scanf("%d %d", &h, &n);
		vector<int> a(n);
		set<int> st;
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]), st.insert(a[i]);
		int ans = 0;
		st.insert(0);
		for (int i = 1; i < n; ++i) {
			if (st.find(a[i]-1) == st.end()) {
				ans++;
			}else {
				i++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
