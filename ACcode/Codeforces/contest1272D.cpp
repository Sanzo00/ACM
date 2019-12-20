#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
 
int L[maxn], R[maxn], a[maxn];
int main() {
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	L[0] = R[n-1] = 1;
	int ans = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i-1]) L[i] = L[i-1] + 1;
		else L[i] = 1;
		ans = max(ans, L[i]);
	}
	for (int i = n-2; i >= 0; --i) {
		if (a[i] < a[i+1]) R[i] = R[i+1] + 1;
		else R[i] = 1;
	}	
	for (int i = 1; i < n-1; ++i) {
		if (a[i+1] > a[i-1])
			ans = max(ans, L[i-1] + R[i+1]);
	}
	cout << ans << endl;
	
	return 0;
}