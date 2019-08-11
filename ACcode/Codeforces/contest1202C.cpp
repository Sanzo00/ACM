#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
string s;
void move(int &x, int &y, int i) {
	if (s[i] == 'D') y++;
	if (s[i] == 'A') y--;
	if (s[i] == 'W') x--;
	if (s[i] == 'S') x++;
}
int first[5], last[5];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> s;
		int len = s.size();
		int x = 0, y = 0, up = 0, down = 0, left = 0, right = 0;
		fill(first, first+5, 0);
		fill(last, last+5, 0);
		for (int i = 0; i < len; ++i) {
			move(x, y, i);
			if (x < up) first[1] = i;
			if (x > down) first[2] = i;
			if (y < left) first[3] = i;
			if (y > right) first[4] = i;
			up = min(up, x);
			down = max(down, x);
			left = min(left, y);
			right = max(right, y);
			if (x == up) last[1] = i;
			if (x == down) last[2] = i;
			if (y == left) last[3] = i;
			if (y == right) last[4] = i;
		}
		long long ww = right - left + 1;
		long long hh = down - up + 1;
		long long ans = 1ll * ww * hh;
		if ((last[2] < first[1] || last[1] < first[2]) && hh > 2) ans = min(ans, 1ll * ww * (hh - 1));
		if ((last[3] < first[4] || last[4] < first[3]) && ww > 2) ans = min(ans, 1ll * (ww - 1) * hh);
		cout << ans << endl;
	}
	return 0;
}