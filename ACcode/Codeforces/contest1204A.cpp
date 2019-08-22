#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string s;
	cin >> s;
	int cnt = 0, ans, len = s.size();
	for (int i = 0; i < (int)s.size(); ++i) {
		cnt += s[i] - '0';
	}
	if (cnt <= 1) ans = len / 2;
	else ans = (len + 1) / 2;
	cout << ans << endl;

	return 0;
}