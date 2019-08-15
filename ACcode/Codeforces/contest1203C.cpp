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
	long long a, b;
	n--;
	cin >> a;
	while (n--) {
		cin >> b;
		a = __gcd(a, b);
	}
	b = 0;
	for (long long i = 1; i <= sqrt(a); ++i) {
		if (a % i == 0) b += 2;
		if (a % i == 0 && a/i == i) b--;
	}
	cout << b << endl;
	return 0;
}