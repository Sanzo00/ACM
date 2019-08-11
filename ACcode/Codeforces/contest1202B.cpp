#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
int a[13][13], b[13][13][13], len;
string s;
int find(int x, int y, int c) {
	int cnt = 1e9;
	for (int i = 1; i <= 100; ++i) {
		for (int j = 0; j <= i; ++j){
			if ((j*x + (i-j)*y) % 10 == c) cnt = min(i - 1, cnt); //cout << i << " - " << j << endl;
		}
	}
	return cnt == 1e9 ? -1 : cnt;
}
void init() {
	for (int i = 0; i <= 9; ++i) {
		for (int j = 0; j <= 9; ++j) {
			for (int k = j; k <= 9; ++k) b[k][j][i] = b[j][k][i] = find(j, k, i);
		}
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s;
	len = s.size();
	init();
	for (int i = 0; i <= 9; ++i) {
		for (int j = i; j <= 9; ++j) {
			int cnt = 0;
			for (int k = 1; k < len; ++k) {
				int cha = s[k] - s[k-1];
				if (cha < 0) cha += 10;
				cnt += b[i][j][cha];
				if (b[i][j][cha] == -1) {
					a[i][j] = -1;
					break;
				}
			}
			if (a[i][j] != -1) a[i][j] = cnt;
		}
		for (int j = i; j <= 9; ++j) a[j][i] = a[i][j];
		for (int j = 0; j <= 9; ++j) cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}