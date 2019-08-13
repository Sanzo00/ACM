#include <bits/stdc++.h>
const int maxn = 2e4 + 5;
using namespace std;
struct ac{
	int u, v, w;
	bool operator < (const ac& t) {
		return w < t.w;
	}
}edge[maxn];
int n, m, s, t, pre[maxn];
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
int Kurskal() {
	for (int i = 0; i < m; ++i) {
		pre[find(edge[i].u)] = pre[find(edge[i].v)];
		if (find(s) == find(t)) {
			return edge[i].w;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= n; ++i) pre[i] = i;
	for (int i = 0; i < m; ++i) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	sort(edge, edge+m);
	cout << Kurskal() << endl;
	return 0;
}