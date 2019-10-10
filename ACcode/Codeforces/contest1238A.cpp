#include <bits/stdc++.h>
const int maxn = 1e7 + 5;
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		a -= b;
		int flag = a > 1;
		puts(flag ? "YES" : "NO");
	}
	return 0;
}
