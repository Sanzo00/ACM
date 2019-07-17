#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
#include <cstring>
const int maxn = 4e2 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
struct ac{
	int v, c, nex;
}edge[maxn << 7];
int head[maxn], curedge[maxn], cnt, s, e;
int dis[maxn];
int a[maxn][maxn];
void init() {
	memset(head, -1, sizeof(head));
	memset(a, 0, sizeof(a));
	cnt = 0;
}
void addedge(int u, int v, int c) {
	edge[cnt] = {v, c, head[u]};
	head[u] = cnt++;
	edge[cnt] = {u, 0, head[v]};
	head[v] = cnt++;
}
int bfs() {
	memset(dis, 0, sizeof(dis));
	dis[s] = 1;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int i = head[u]; i != -1; i = edge[i].nex) {
			int v = edge[i].v;
			int c = edge[i].c;
			if (dis[v] || c == 0) continue;
			dis[v] = dis[u] + 1;
			que.push(v);
		}
	}
	return dis[e] > 0;
}
int dfs(int u, int flow) {
	if (u == e || flow == 0) return flow;
	for (int &i = curedge[u]; i != -1; i = edge[i].nex) {
		int v = edge[i].v;
		int c = edge[i].c;
		if (dis[v] != dis[u] + 1) continue;
		int tmp = dfs(v, min(flow, c));
		if (tmp > 0) {
			edge[i].c -= tmp;
			edge[i^1].c += tmp;
			return tmp;
		}
	}
	dis[u] = -1;
	return 0;
}
int Dinic() {
	int ans = 0, tmp;
	while (bfs()) {
		for (int i = 0; i <= e; ++i) curedge[i] = head[i];
		while ((tmp = dfs(s, inf)) > 0) ans += tmp;
	}
	return ans;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, q;
    while (cin >> n) {
    	init();
    	map<string, int> mp;
    	int num = 0;
    	vector<string> have(maxn), device(maxn);
    	for (int i = 0; i < n; ++i) {
    		cin >> have[i];
    		if (mp[have[i]] == 0) mp[have[i]] = ++num;
    	}
    	cin >> m;
    	for (int j = 0; j < m; ++j) {
    		cin >> device[j] >> device[j];
    		if (mp[device[j]] == 0) mp[device[j]] = ++num;
    	}
    	cin >> q;
    	for (int i = 0; i < q; ++i) {
    		string l, r;
    		cin >> l >> r;
    		if (mp[l] == 0) mp[l] = ++num;
    		if (mp[r] == 0) mp[r] = ++num;
    		addedge(mp[l], mp[r], inf);
    	}
    	s = 0, e = num + 1;
    	for (int i = 0; i < m; ++i) addedge(s, mp[device[i]], 1);
    	for (int i = 0; i < n; ++i) addedge(mp[have[i]], e, 1);
    	cout << m - Dinic() << endl;
    }
    return 0;
}