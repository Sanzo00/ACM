#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int edge[maxn];
int fan(int x) {
	int sum = 0;
	for (int i = 0; (1 << i) <= x; ++i) {
		if (((1 << i) & x) == 0) {
			sum += 1 << i;
		}
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int sum = 0;
		for (int i = 2; i <= n; ++i) {
			int t = fan(i);
			if ((i & 1) == 0) edge[i] = 1;
			else {
				if (t == 0 && i+1 > n) edge[i] = 1;
				else if (t == 0 && i+1 <= n) edge[i] = i+1;
				else {
					int last = 0;
					for (int j = 0; (1 << j) <= i; ++j) {
						if (((1 << j) & i) == 0) {
							last = 1 << j;
							break;
						}
					}
					edge[i] = last;
				}
			}
			sum += i & edge[i];
		}
		cout << sum << endl;
		for (int i = 2; i <= n; ++i) {
			if (i > 2) cout << " ";
			cout << edge[i];
		}
		cout << endl;
	}
	return 0;
}