#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <algorithm>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int dis[maxn], cnt[maxn], vis[maxn];
vector<pair<int,int> > g[maxn];
int Spfa(int s, int n) {
	memset(dis, inf, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	memset(vis, 0, sizeof(vis));
	int sum = 0, in = 1; // long long
	deque<int> que;
	que.push_back(s);
	dis[s] = 0;
	vis[s] = 1;
	cnt[s] = 1;
	while (!que.empty()) {
		int u = que.front();
		while (dis[u] * in > sum) { // LLL优化
			que.pop_front();
			que.push_back(u);
			u = que.front();			
		}
		que.pop_front();
		vis[u] = 0;
		in--;
		sum -= dis[u];
		for (int i = 0; i < (int)g[u].size(); ++i) {
			int v = g[u][i].first;
			int c = g[u][i].second;
			if (dis[v] > dis[u] + c) {	
				dis[v] = dis[u] + c;
				if (vis[v]) continue;
				if (!que.empty() && dis[v] <= dis[que.front()]) que.push_front(v); // SLF优化
				else que.push_back(v);
				vis[v] = 1;
				in++;
				sum += dis[v];
				if (++cnt[v] > n) return 1; // 判断负环
			}
		}
	}
	return 0;
}

int spfa(int s, int n) {
	memset(dis, inf, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	queue<int> que;
	que.push(s);
	dis[s] = 0;
	vis[s] = 1;
	cnt[s] = 1;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		vis[u] = 0;
		for (int i = 0; i < (int)g[u].size(); ++i) {
			int v = g[u][i].first;
			int c = g[u][i].second;
			if (dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				if (vis[v]) continue;
				vis[v] = 1;
				que.push(v);
				if (++cnt[v] > n) return 1;
			}
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, u, v, c, w;
		scanf("%d %d %d", &n, &m, &w);
		for (int i = 0; i <= n; ++i) g[i].clear();
		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &u, &v, &c);
			g[u].push_back(make_pair(v, c));
			g[v].push_back(make_pair(u, c));
		}
		for (int i = 0; i < w; ++i) {
			scanf("%d %d %d", &u, &v, &c);
			g[u].push_back(make_pair(v, -c));
		}
		if (spfa(1, n)) puts("YES");
		else puts("NO");
	}
	return 0;
}