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
struct ac{
	int u, v, c;
	bool operator< (const ac &t) {
		return t.c > c;
	}
};
LL d[maxn], cnt[maxn];
int pre[maxn];
vector<ac> g;
vector<int> a;
int find(int x) {
	int tx = x, t;
	while (x != pre[x]) x = pre[x];
	while (pre[tx] != x) {
		t = pre[tx];
		pre[tx] = x;
		tx = t;
	}
	return x;
}
void join(int x, int y, int t) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) return;
	d[t] += cnt[fx] * cnt[fy];
	cnt[fx] += cnt[fy];
	pre[fy] = fx;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m, q, id;
    while (cin >> n >> m >> q) {
    	a.clear();
    	g.clear();
	    for (int i = 0; i < maxn; ++i) pre[i] = i, cnt[i] = 1, d[i] = 0;
	    for (int i = 0; i < m; ++i) {
	    	ac t;
	    	cin >> t.u >> t.v >> t.c; 
	    	a.push_back(t.c);
	    	g.push_back(t);
	    }
	    sort(a.begin(), a.end());
	    sort(g.begin(), g.begin() + m);
	    a.erase(unique(a.begin(), a.end()), a.end());
	    for (int i = 0; i < m; ++i) {
	    	id = lower_bound(a.begin(), a.end(), g[i].c) - a.begin() + 1;
	    	join(g[i].u, g[i].v, id);
	    }
	    for (int i = 1; i <= m; ++i) {
	    	d[i] += d[i - 1];
	    }
	    for (int i = 0, x; i < q; ++i) {
	    	cin >> x;
	    	if (x == 0) {
	    		cout << 0 << endl;
	    		continue;
	    	}
	    	x = upper_bound(a.begin(), a.end(), x) - a.begin();
	    	cout << d[x] << endl;
	    }
    }
    return 0;
}