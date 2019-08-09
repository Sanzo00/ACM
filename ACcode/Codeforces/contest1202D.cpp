#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
long long num(long long x) {return x * (x - 1) / 2;}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		long long  cnt3 = sqrt((n * 2));
		while (num(cnt3) <= n) cnt3++;
		while (num(cnt3) > n) cnt3--;
		n -= num(cnt3);
		int tmp = cnt3;
		string s = "7";
		while (n && tmp) {
			while (num(tmp) <= n) {
				n -= num(tmp);
				s += "7";
			}
			s += "3";
			tmp--;
		}
		for (int i = 0; i < tmp; ++i) s += "3";
		s += "1";
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}