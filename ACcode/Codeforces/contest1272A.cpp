#include <bits/stdc++.h>
using namespace std;
long long dis(int a, int b, int c) {
	long long ans = abs(a - b) + abs(a - c) + abs(b - c);	
	return ans;
}
int main() {
	int n, a, b, c;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		long long ans = 4e18;
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				for (int k = -1; k <= 1; ++k) {
					ans = min(ans, dis(a+i, b+j, c+k));
				}
			}
		
		}
		cout << ans << endl;
	}
	
	return 0;
}