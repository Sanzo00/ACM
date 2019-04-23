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
struct cmp{
	bool operator() (P x, P y) {
		return x.first < y.first;
	}
};
vector<P> g[maxn];
int vis[maxn], dis[maxn], cnt[maxn];
void add(int u, int v, int c) {
	// cout << u << "->" << v << " " << c << endl;
	g[u].push_back(make_pair(c, v));
}
int Spfa(int s, int e) {
	mem(vis, 0);
	mem(dis, inf);
	mem(cnt, 0);
	dis[s] = 0;
	priority_queue<P, vector<P>, cmp> que;
	que.push(make_pair(0, s));
	vis[s] = 1;
	cnt[s] = 1;
	while (!que.empty()) {
		P f = que.top();
		que.pop();
		// cout << vis[f.second] << " " << dis[f.second] << " " << f.first << endl;
		if (dis[f.second] < f.first || vis[f.second] == 0) continue;
		// cout << f.first << " " << f.second << endl;
		vis[f.second] = 0;
		int len = g[f.second].size();
		for (int i = 0; i < len; ++i) {
			P y = g[f.second][i];
			if (dis[y.second] <= f.first + y.first) continue;
			dis[y.second] = f.first + y.first;
			que.push(make_pair(dis[y.second], y.second));
			if (vis[y.second] == 0 && ++cnt[y.second] >= e) 
				return -1;
			else vis[y.second] = 1;
		}
	}
	return dis[e];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, s = 1e9, e = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	int a, b, k;
    	cin >> a >> b >> k;
    	e = max(e, b+1);
    	s = min(s, a);
    	add(a, b+1, k);
    }
    // cout << e << endl;
    for (int i = s; i <= e; ++i) {
    	add(i-1, i, 1);
    	add(i, i-1, 0);
    }
    int ans = Spfa(s, e);
    cout << ans << endl;
    return 0;
}