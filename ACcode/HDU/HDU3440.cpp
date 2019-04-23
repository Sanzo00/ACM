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

vector<P>g[maxn];
int dis[maxn], vis[maxn], cnt[maxn];
int n, m;
int Spfa(int s, int e) {
	queue<int> que;
	mem(dis, inf);
	mem(vis, 0);
	mem(cnt, 0);
	dis[s] = 0;
	que.push(s);
	cnt[s]++;
	vis[s] = 1;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		vis[u] = 0;
		int len = g[u].size();
		for (int i = 0; i < len; ++i) {
			int v = g[u][i].second;
			int c = g[u][i].first;
			if (dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				if (!vis[v]) {
					que.push(v);
					vis[v] = 1;
					cnt[v]++;
					if (cnt[v] > n) return -1;
				}
			}
		}
	}
	if (dis[e] == inf) return -2;
	return dis[e];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T, Case = 1, ans;
    cin >> T;
    while (T--) {
    	cout << "Case " << Case++ << ": ";
    	cin >> n >> m;
    	ans = 0;
    	for (int i = 0; i < n; ++i) g[i].clear();
    	vector<int> a(n), b(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    	}
		iota(b.begin(), b.end(), 0);
    	sort(b.begin(), b.end(), [&](int x, int y){
    		if (a[x] != a[y]) return a[x] < a[y];
    		else return x < y;
    	});
    	for (int i = 0; i < n-1; ++i) {
    		g[i+1].push_back(make_pair(-1, i));
    		int u = min(b[i], b[i+1]);
    		int v = max(b[i], b[i+1]);
    		g[u].push_back(make_pair(m, v));
    		if (u - v > m) {
    			ans = -1;
    			break;
    		}
    	}
    	if (ans == -1) {
    		cout << -1 << endl;
    		continue;
    	}
    	int s = min(b[0], b[n-1]);
    	int e = max(b[n-1], b[0]);
	 	int ans = Spfa(s, e);
	 	cout << ans << endl;
    }
	 	
    return 0;
}