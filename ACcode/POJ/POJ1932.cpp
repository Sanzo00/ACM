#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <time.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
vector<int> g[maxn];
int dis[maxn], vis[maxn], cnt[maxn], val[maxn];
int mp[maxn][maxn];
int n;
int Spfa(int s, int e) {
	for (int i = 1; i <= e; ++i) {
		dis[i] = -inf;
	}
	mem(vis, 0);
	mem(cnt, 0);
	vis[s] = 1;
	cnt[s] = 1;
	dis[s] = 100;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		vis[f] = 0;
		if (cnt[f] >= n) dis[f] = inf;
		int len = g[f].size();
		for (int i = 0; i < len; ++i) {
			int t = g[f][i];
			if (dis[t] < dis[f] + val[t] && dis[f] + val[t] > 0) {
				dis[t] = dis[f] + val[t];
				if (vis[t] == 0 && ++cnt[t] <= n) {
					vis[t] = 1;
					que.push(t);
				}
				if (cnt[t] > e) return -1;
			}
		}
	}
	return dis[e] > 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (scanf("%d", &n) != EOF) {
    	mem(mp, 0);
    	if (n == -1) break;
    	for (int i = 0; i <= n; ++i) g[i].clear();
    	int num, d;
    	for (int i = 1; i <= n; ++i) {
    		scanf("%d%d", &val[i], &num);
    		for (int j = 0; j < num; ++j) {
    			scanf("%d", &d);
    			g[i].push_back(d);
    			mp[i][d] = 1;
    		}
    	}
    	int ans = Spfa(1, n);
    	if (ans == -1){
    		for (int k = 1; k <= n; ++k) {
    			for (int i = 1; i <= n; ++i) {
    				for (int j = 1; j <= n; ++j) {
    					if (mp[i][k] && mp[k][j]) mp[i][j] = 1;
    				}
    			}
    		}
    		for (int i = 1; i <= n; ++i) {
    			if (mp[1][i] && mp[i][n] && cnt[i] > n) {
    				ans = 1;
    				break;
    			}
    		}
    	}
    	if (ans == 1) puts("winnable");
    	else puts("hopeless");
    }
    return 0;
}