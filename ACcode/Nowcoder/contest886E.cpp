#include <bits/stdc++.h>
const int maxn = 2e3 + 2;
using namespace std;
int f[maxn], g[maxn][maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T, Case = 1;
	cin >> T;
	while (T--) {
		cout << "Case #" << Case++ << ": "; 
		int n;
		cin >> n;
		if (n % 4 > 1) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		for (int i = 1; i <= n; ++i) {
			f[i] = i;
			for (int j = 1; j <= n; ++j) {
				g[i][j] = 0;
			}
		}
		for (int i = 1; i <= n/4; ++i) {
			g[i*4-3][i*4-2] = g[i*4-2][i*4-3] = 1;
			g[i*4-2][i*4-1] = g[i*4-1][i*4-2] = 1;
			g[i*4-1][i*4] = g[i*4][i*4-1] = 1;
			for (int j = 1; j <= i*4-4; ++j) {
				g[j][i*4-2] = g[i*4-2][j] = 1;
				g[j][i*4-1] = g[i*4-1][j] = 1;
			}
		}
		for (int i = 1; i <= n/4; ++i) {
			int j = i*4 - 3;
			swap(f[j], f[j+1]);
			swap(f[j+1], f[j+3]);
			swap(f[j+2], f[j+3]);
		}
		if (n & 1) {
			for (int i = 1; i <= n/4; ++i) {
				g[n][i*4-2] = g[i*4-2][n] = 1;
				g[n][i*4-1] = g[i*4-1][n] = 1;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cout << g[i][j];
			}cout << endl;
		}
		for (int i = 1; i <= n; ++i) {
			if (i > 1) cout << " ";
			cout << f[i];
		}cout << endl;
	}
	return 0;
}