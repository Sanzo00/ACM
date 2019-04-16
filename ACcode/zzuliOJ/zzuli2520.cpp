#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 1e5 + 7;
int tot;
vector<int> g[maxn];
LL a[maxn], b[maxn], c[maxn], ans[maxn], n, k;
void Add(int x) {
	x++;
	while (x <= n) {
		c[x]++;
		x += lowbit(x);
	}
}
LL Sum(int x) {
	x++;
	LL ans = 0;
	while (x) {
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
void dfs(int x) {
	int l, r;
	l = lower_bound(b, b + tot, a[x-1]-k) - b - 1;
	r = upper_bound(b, b + tot, a[x-1]+k) - b - 1;
	ans[x] -= Sum(r) - Sum(l);
	LL sum = 0;
	for (int it : g[x]) {
		dfs(it);
		sum += ans[it];
	}
	int pos = lower_bound(b, b + tot, a[x-1]) - b;
	Add(pos);
	l = lower_bound(b, b + tot, a[x-1]-k) - b - 1;
	r = upper_bound(b, b + tot, a[x-1]+k) - b - 1;
	ans[x] += Sum(r) - Sum(l) + sum;
	return;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    scanf("%lld %lld", &n, &k);
    for (int i = 0; i < n; ++i) {
    	scanf("%lld", &a[i]);
    	b[i] = a[i];
    }
    sort(b, b + n);
    tot = unique(b, b + n) - b;
    for (int i = 2, x; i <= n; ++i) {
    	scanf("%d", &x);
    	g[x].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
    	printf("%lld\n", ans[i]);
    }
    return 0;
}
