#include <bits/stdc++.h>
const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int R[maxn], C[maxn];
int a[maxn][maxn], b[maxn][maxn];
long long quick(long long a, long long b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int h, w;
	cin >> h >> w;
	for (int i = 1; i <= h; ++i) cin >> R[i];
	for (int i = 1; i <= w; ++i) cin >> C[i];
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= R[i]; ++j) {
			b[i][j] = 1;
		}
	}
	for (int i = 1; i <= w; ++i) {
		for (int j = 1; j <= C[i]; ++j) {
			b[j][i] = 1;
		}
	}
	int flag = 1;
	for (int i = 1; i <= h; ++i) {
		int tmp = 0;
		for (int j = 1; j <= w; ++j) {
			if (b[i][j]) tmp++;
			else break;
		}
		if (tmp != R[i]) flag = 0;
	}
	for (int i = 1; i <= w; ++i) {
		int tmp = 0;
		for (int j = 1; j <= h; ++j) {
			if (b[j][i]) tmp++;
			else break;
		}
		if (tmp != C[i]) flag = 0;
	}
	if (flag == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= h; ++i) {
		for (int j = R[i]+2; j <= w; ++j) {
			a[i][j]++;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= w; ++i) {
		for (int j = C[i]+2; j <= h; ++j) {
			a[j][i]++;
			if (a[j][i] == 2) cnt++;
		}
	}
	
	long long ans = quick(2, cnt);
	cout << ans << endl;
	return 0;
}
