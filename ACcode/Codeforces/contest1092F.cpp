#include <bits/stdc++.h>
#define LL long long
#define P pair<LL, LL>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 5e5 + 7;
vector<P> g[maxn];
LL sum[maxn], a[maxn];
LL tmp = 0, ans = 0;
void dfs(int x, int fa, LL h) {
	sum[x] = a[x];
	tmp += 1ll * a[x] * h;
	for (auto it : g[x]) {
		if (it.first == fa) continue;
		dfs(it.first, x, h + it.second);
		sum[x] += sum[it.first];
	}
}
void go(int x, int fa) {
	ans = max(ans, tmp);
	// cout << x << " " << ans << endl;
	for (auto it : g[x]) {
		if (it.first == fa) continue;
		tmp -= it.second * sum[it.first];
		// cout << sum[it.first] << endl;
		sum[x] -= sum[it.first];
		tmp += it.second * sum[x];
		sum[it.first] += sum[x];
		// cout << tmp << endl;

		go(it.first, x);

		sum[it.first] -= sum[x];
		tmp -= it.second * sum[x];	
		sum[x] += sum[it.first];
		tmp += it.second * sum[it.first];
	}
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];	
    for (int i = 0, x,y; i < n-1; ++i) {
    	cin >> x >> y;
    	g[x].push_back(make_pair(y, 1));
    	g[y].push_back(make_pair(x, 1));
    }
    
    dfs(1, 0, 0);
   	go(1, 0);
   	cout << ans << "\n";

    return 0;
}