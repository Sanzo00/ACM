#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
#define P pair<int,int>
using namespace std;
struct ac{
	int u, v, l, a;
	bool operator < (const ac &t) {
		return a > t.a;
	}
}edge[maxn];
int dis[maxn], vis[maxn];
vector<ac> g[maxn];
struct reset_kruskal{
	struct ac{
		int v, nex;
	}edge[maxn];
	struct acc{
		int l, a;
	}weight[maxn];
	int head[maxn], pre[maxn], cnt, n, ans;
	int dep[maxn], vis[maxn], fa[maxn][31];
	void init(int t) {
		n = t;
		cnt = 0;
		for (int i = 0; i <= n; ++i) {
			weight[i].l = inf;
			pre[i] = i;
		}
		fill(head, head+n+1, -1);
		fill(vis, vis+n+1, 0);

	}
	void add(int u, int v) {
		edge[cnt] = {v, head[u]};
		head[u] = cnt++;
	} 
	void dfs (int u) { // 预处理lca
		vis[u] = 1;
		for (int i = 1; i <= log2(n); ++i) {
			if (fa[u][i-1] == 0) break;
			fa[u][i] = fa[fa[u][i-1]][i-1];
		}
		for (int i = head[u]; ~i; i = edge[i].nex) {
			int v = edge[i].v;
			dep[v] = dep[u] + 1;
			fa[v][0] = u; 
			dfs(v);
			weight[u].l = min(weight[u].l, weight[v].l);
		}
	}
	int lca(int v, int p) {
		for (int i = log2(dep[v]); i >= 0; --i) {
			if (weight[fa[v][i]].a > p) v = fa[v][i];
		}
		return v;
	}
	int find (int x) {
		int t = x;
		while (x != pre[x]) x = pre[x];
		while (t != pre[t]) {
			int fa = pre[t];
			pre[t] = x;
			t = fa;
		}
		return x;
	}
}kru;
void dijkstra(int s, int n) {
	fill(dis, dis+n+1, inf);
	fill(vis, vis+n+1, 0);
	dis[s] = 0;
	priority_queue<P, vector<P>, greater<P>> que;
	que.push(P(0, s));
	while (!que.empty()) {
		P top = que.top();
		int u = top.second;
		que.pop();
		if (vis[u] || dis[u] < top.first) continue;
		vis[u] = 1;
		for (int i = 0; i < (int)g[u].size(); ++i) {
			int v = g[u][i].v;
			int l = g[u][i].l;
			if (vis[v] == 0 && dis[u] + l < dis[v]) {
				dis[v] = dis[u] + l;
				que.push(P(dis[v], v));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1;  i <= n; ++i) {
			g[i].clear();
		}
		for (int i = 0; i < m; ++i) {
			int u, v, l, a;
			scanf("%d %d %d %d", &u, &v, &l, &a);
			edge[i] = {u, v, l, a};
			g[u].push_back({u, v, l, a});
			g[v].push_back({v, u, l, a});
		}
		dijkstra(1, n);
		sort(edge, edge+m);
		kru.init(n*2);
		int cnt = n;
		for (int i = 0; i < m; ++i) {
			int fu = kru.find(edge[i].u);
			int fv = kru.find(edge[i].v);
			if (fu == fv) continue;
			cnt++;
			kru.weight[cnt].a = edge[i].a;
			kru.weight[edge[i].u].l = dis[edge[i].u];
			kru.weight[edge[i].v].l = dis[edge[i].v];
			kru.add(cnt, fu);
			kru.add(cnt, fv);
			kru.pre[fu] = kru.pre[fv] = cnt;
		}
		for (int i = cnt; i >= 1; --i) {
			if (kru.vis[i] == 0) {
				kru.dep[i] = 1;
				kru.fa[i][0] = i;
				kru.dfs(i);
			}
		}
		int ans = 0;
		int q, k, s;
		scanf("%d %d %d", &q, &k, &s);
		while (q--) {
			int v, p;
			scanf("%d %d", &v, &p);
			v = ((v + k * ans - 1) % n)  + 1;
			p = (p + k * ans) % (s + 1);
			printf("%d\n", ans = kru.weight[kru.lca(v, p)].l);
		}
	}
	return 0;
}