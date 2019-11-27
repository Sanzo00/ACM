#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
 
int main() {
	int T;
	cin >> T;
	while (T--) {
		long long x, y;
		cin >> x >> y;
		int flag = 0;
		for (int i = 0; i < 10000; ++i) {
			//cout << x << endl;
			if (x >= y) flag = 1;
			if (x % 2 == 0) x = x / 2 * 3;
			else x--;
			
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}
