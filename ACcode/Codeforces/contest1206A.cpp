#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	cin >> m;
	vector<int> b(m);
	for (int j = 0; j < m; ++j) cin >> b[j];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	cout << a.back() << " " << b.back() << endl;
	return 0;
}