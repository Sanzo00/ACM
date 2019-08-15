#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	set<int> st;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		int t = a[i];
		if (t == 1 || st.find(t-1) != st.end()) t = t;
		else t--;
		if (st.find(t) != st.end()) t++;
		st.insert(t);
	}
	cout << st.size() << endl;
	return 0;
}