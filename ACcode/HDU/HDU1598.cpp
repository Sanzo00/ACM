#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'        
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int pre[maxn];
struct ac{
	int u, v, w;
	bool operator < (const ac &t) {
		return w < t.w;
	}
}a[maxn];
int n, m;
int find(int x) {
	// return (pre[x] == x) ? x : pre[x] = find(pre[x]);
	int tx = x;
	while (x != pre[x]) {
		x = pre[x];
	}
	int t;
	while (pre[tx] != x) {
		t = pre[tx];
		pre[tx] = x;
		tx = t;
	}
	return x;
}
void join(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) return;
	pre[fy] = fx;
}
int check(int x, int s, int e) {
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j <= n; ++j) pre[j] = j;
		int w = a[i].w;
		for (int j = 0; j < m; ++j) {
			if (a[j].w < w || a[j].w - w > x) continue;
			join(a[j].u, a[j].v);
			if (find(s) == find(e)) return 1;
		}		
	}
	return 0;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m) {
    	int tmp = 0;
	    for (int i = 0; i < m; ++i) {
	    	cin >> a[i].u >> a[i].v >> a[i].w;
	    	tmp = max(tmp, a[i].w);
	    }
	    sort(a, a + m);
	    int q;
	    cin >> q;
	    while (q--) {
	    	int s, e;
	    	cin >> s >> e;
	    	int l = 0, r = tmp-1;
	    	while (l <= r) {
	    		if (check(mid, s, e)) r = mid - 1;
	    		else l = mid + 1;
	    	}
	    	int ans = l;
	    	if (ans == tmp) ans = -1;
	    	cout << ans << endl;
	    }
    }
    return 0;
}