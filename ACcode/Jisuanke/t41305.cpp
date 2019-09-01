#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int dis[maxn], cnt[maxn], vis[maxn];
vector<pair<int,int>> g[maxn];
int Spfa(int s, int n) {
	memset(dis, inf, sizeof(dis));
	// memset(cnt, 0, sizeof(cnt));
	memset(vis, 0, sizeof(vis));
	int sum = 0; // long long
	int in = 1;
	deque<int> que;
	que.push_back(s);
	dis[s] = 0;
	vis[s] = cnt[s] = 1;
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
			// printf("%d %d - %d\n", u, v, c);
			if (dis[v] > dis[u] + c) {	
				dis[v] = dis[u] + c;
				if (vis[v]) continue;
				if (!que.empty() && dis[v] <= dis[que.front()]) que.push_front(v); // SLF优化
				else que.push_back(v);
				// printf("%d\n", que.size());
				vis[v] = 1;
				in++;
				sum += dis[v];
				// if (++cnt[v] > n) return 1; // 判断负环
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
	vis[s] = 1;
	cnt[s] = 1;
	dis[s] = 0;
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
		int n, m, u, v, c;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) g[i].clear();
		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &u, &v, &c);
			g[u].push_back(make_pair(v, c));
		}
		for (int i = 0; i < 6; ++i) {
			scanf("%d %d", &u, &v);
			// Spfa(v, n);
			spfa(v, n);
			int ans = dis[u];
			printf("%d\n", -ans);
			g[u].push_back(make_pair(v, -ans));
		}
	}
	return 0;
}