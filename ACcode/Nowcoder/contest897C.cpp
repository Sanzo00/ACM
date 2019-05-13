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
vector<P> g[maxn];
int dp[maxn][3];
LL ans;
void dfs1(int u, int fa) {
	mem(dp[u], 0);
	dp[u][0] = 1;
	for (auto it : g[u]) {
		int v = it.first;
		int w = it.second;
		if (v == fa) continue;
		dfs1(v, u);
		dp[u][0] += dp[v][(3 - w) % 3];
		dp[u][1] += dp[v][(4 - w) % 3];
		dp[u][2] += dp[v][(5 - w) % 3];
	}
}
void dfs2(int u, int fa, int sum0, int sum1, int sum2) {
	ans += sum0 - 1;
	for (auto it : g[u]) {
		int v = it.first;
		int w = it.second;
		if (v == fa) continue;
		int other[3];
		other[0] = sum0 - dp[v][(3-w)%3];
		other[1] = sum1 - dp[v][(4-w)%3];
		other[2] = sum2 - dp[v][(5-w)%3];
		dfs2(v, u, other[(3-w)%3]+dp[v][0], other[(4-w)%3]+dp[v][1], other[(5-w)%3]+dp[v][2]);
	}
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i <= n; ++i) {
            g[i].clear();
        }
        for (int i = 1, u,v,w; i < n; ++i) {
            cin >> u >> v >> w;
            g[u].push_back(make_pair(v, w%3));
            g[v].push_back(make_pair(u, w%3));
        }
        ans = 0;
        dfs1(1, 0);
        dfs2(1, 0, dp[1][0], dp[1][1], dp[1][2]);
        cout << ans / 2 << endl;
    }
 
    return 0;
}