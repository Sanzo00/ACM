#include <bits/stdc++.h>
const int maxn = 3e5 + 5;
using namespace std;
struct ac{
	int u, v, w;
	bool operator < (const ac &t) {
		return w < t.w;
	}
}edge[maxn];
struct reset_kruskal{
	struct ac{
		int v, nex;
	}edge[maxn];
	int head[maxn], pre[maxn], cnt, n;
	int dep[maxn], vis[maxn], fa[maxn][31], weight[maxn];
	void init(int t) {
		n = t;
		cnt = 0;
		for (int i = 0; i <= n; ++i) pre[i] = i;
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
		}
	}
	int lca(int u, int v) {
		if (dep[u] < dep[v]) swap(u, v);
		int det = dep[u] - dep[v];
		for (int i = 0; i <= log2(det); ++i) {
			if (det & (1 << i)) u = fa[u][i];
		}
		if (u == v) return u;
		for (int i = log2(dep[u]); i >= 0; --i) {
			if (fa[u][i] != fa[v][i]) {
				u = fa[u][i];
				v = fa[v][i];
			}
		}
		return fa[u][0];
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
	}
	sort(edge, edge+m);
	kru.init(n*2);
	int cnt = n;
	for (int i = 0; i < m; ++i) {
		int fu = kru.find(edge[i].u);
		int fv = kru.find(edge[i].v);
		if (fu == fv) continue;
		cnt++;
		kru.weight[cnt] = edge[i].w;
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
	int q;
	scanf("%d", &q);
	while (q--) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (kru.find(u) != kru.find(v)) puts("impossible");
		else printf("%d\n", kru.weight[kru.lca(u, v)]);
	}
	return 0;
}