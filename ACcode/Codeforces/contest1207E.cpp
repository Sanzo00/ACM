#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << "?";
	for (int i = 0; i < 100; ++i)  cout << " " << i;
	cout << endl;
	fflush(stdout);

	int a, ans = 0;
	cin >> a;
	ans = a >> 7;
	ans <<= 7;
	cout << "?";
	for (int i = 1; i <= 100; ++i) cout << " " << (i << 7);
	cout << endl;
	fflush(stdout);
	cin >> a;
	a &= (1 << 7) - 1;
	ans |= a;
	cout << "! " << ans << endl;
	fflush(stdout);
	return 0;
}