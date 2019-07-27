#include <bits/stdc++.h>
const int maxn = 5e2 + 1;
const int inf = 0x3f3f3f3f;
using namespace std;
int a[maxn][maxn];
int up[maxn], down[maxn];
int q[maxn][2];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> a[i][j];
			}
		}
		int ans = 1;
		for (int i = 1; i <= n; ++i) { // 上界
			for (int j = 1; j <= n; ++j) {
				up[j] = -inf;
				down[j] = inf;
			}
			for (int j = i; j <= n; ++j) { // 下界
				for (int k = 1; k <= n; ++k) { // 更新列的最值
					up[k] = max(up[k], a[j][k]);
					down[k] = min(down[k], a[j][k]);
				}
				int l = 1, h0 = 0, h1 = 0, t0 = 1, t1 = 1;
				for (int r = 1; r <= n; ++r) { // 枚举右端点
					while (h0 >= t0 && down[q[h0][0]] >= down[r]) h0--; // 最大值递增
					while (h1 >= t1 && up[q[h1][1]] <= up[r]) h1--; // 最小值递减
					q[++h0][0] = q[++h1][1] = r;
					while (l <= r && up[q[t1][1]] - down[q[t0][0]] > m) { // 不满足m，左区间L++
						l++;
						while (t1 <= h1 && q[t1][1] < l) ++t1; // 更新队列头指针
						while (t0 <= h0 && q[t0][0] < l) ++t0;
					}
					ans = max(ans, (r-l+1) * (j-i+1));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

