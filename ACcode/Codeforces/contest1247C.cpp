#include <bits/stdc++.h>
const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;
using namespace std;
int get(long long x) {
	return __builtin_popcount(x);
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, p;
	scanf("%d %d", &n, &p);
	int now = 1;
	int flag = 0;
	while (1) {
		if (flag) {
			cout << -1 << endl;
			break;
		}
		long long x = n - now*p;
		int tmp = get(x);
		if (now > x) flag = 1;
		if (now >= tmp && now <= x) {
			cout << now << endl;
			break;
		}
		now++;
	}
	return 0;
}
