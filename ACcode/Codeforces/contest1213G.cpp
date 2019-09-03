#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
struct ac{
	int u, v, c;
	bool operator < (const ac &t) {
		return c < t.c;
	}
}a[maxn];
int b[maxn], c[maxn], pre[maxn], cnt[maxn];
long long q[maxn];
long long C(int x) {
	return 1ll * x * (x - 1) / 2;
}
void init(int n) {
	for (int i = 0; i <= n; ++i) pre[i] = i;
	fill(cnt, cnt+n+1, 1);
	fill(q, q+n+1, 0);
}
int find(int x) {
	int t = x;
	while (x != pre[x]) x = pre[x];
	while (pre[t] != x) {
		int fa = pre[t];
		pre[t] = x;
		t = fa;
	}
	return x;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		init(n);
		for (int i = 0; i < n-1; ++i) scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].c);
		sort(a, a+n-1);
		for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
		for (int i = 0; i < m; ++i) c[i] = i;
		sort(c, c+m, [&](int x, int y) {
			return b[x] < b[y];
		});
		long long ans = 0;
		int now = 0;
		for (int i = 0; i < m; ++i) {
			while (now < n-1 && a[now].c <= b[c[i]]) {
				int fu = find(a[now].u);
				int fv = find(a[now].v);
				if (fu == fv) {
					now++;
					continue;
				}
				ans += C(cnt[fu] + cnt[fv]) - C(cnt[fu]) - C(cnt[fv]);
				pre[fu] = fv;
				cnt[fv] += cnt[fu];
				++now;
			}
			q[c[i]] = ans; 
		}
		for (int i = 0; i < m; ++i) {
			if (i) printf(" ");
			printf("%lld", q[i]);
		}
		puts("");
	}
	return 0;
}