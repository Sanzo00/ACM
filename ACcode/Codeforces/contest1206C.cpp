#include <bits/stdc++.h>
const int maxn = 3e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int a[maxn];
long long sum[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	int t = n * 2;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) a[i] = t--, a[i+n] = t--;
		else a[i+n] = t--, a[i] = t--;
	}
	set<int> st;
	n *= 2;
	for (int i = n; i < n+n/2-1; ++i) a[i] = a[i-n];
	sum[0] = a[0];
	for (int i = 1; i < n+n/2-1; ++i) sum[i] = a[i] + sum[i-1];
	st.insert(sum[n/2-1]);
	for (int i = n/2; i < n+n/2-1; ++i) st.insert(sum[i] - sum[i-n/2]);
	if (st.size() > 2) cout << "NO\n";
	else{
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			if (i) cout << " ";
			cout << a[i];
		}
		cout << endl;
	}
	return 0;
}