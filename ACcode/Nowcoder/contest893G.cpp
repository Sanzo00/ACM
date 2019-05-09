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
int vis[maxn<<1], sz[maxn<<1], pre[maxn<<1];
int ans[maxn], n, m;
int find (int x) {
	return (x == pre[x]) ? x : pre[x] = find(pre[x]);
}
void join(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) return;
	pre[fy] = fx;
	sz[fx] += sz[fy];
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		int fx = find(i); 
		int fy = find(i+n);
		if (fx == fy) {
			cout << -1 << endl;
			return;
		}
		if (vis[fx] == 0) {
			if (sz[fx] > sz[fy]) {
				vis[fx] = 1;
				vis[fy] = -1;
			}else {
				vis[fy] = 1;
				vis[fx] = -1;
			}
		}
		ans[i] = (vis[fx] == 1);
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i];
	}
	cout << endl;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {	
	    cin >> n >> m;
	    for (int i = 1; i <= n*2; ++i) {
    		pre[i] = i;
    		sz[i] = (i <= n);
    		vis[i] = 0;
    	}
	    for (int i = 0, u,v,w; i < m; ++i) {
	    	cin >> u >> v >> w;
	    	if (w) {
	    		join(u, v);
	    		join(u+n, v+n);
	    	}else {
	    		join(u, v+n);
	    		join(u+n, v);
	    	}
	    }
	    solve();
    }
    return 0;
}	