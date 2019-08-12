// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <set>
const int maxn = 1e5 + 5;
using namespace std;
vector<int> g[maxn];
struct Topsort{ // 下标1
	priority_queue<int, vector<int>, greater<int> > q1; // 字典序小，正向建图
	priority_queue<int, vector<int> > q2; // 编号小的优先级高，反向建图
	int in[maxn], order[maxn], n, cnt, ans[maxn];
	void init () {
		fill(in, in+n+1, 0);
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < (int)g[i].size(); ++j) {
				in[g[i][j]]++;
			}
		}
	}	
	int min_num (int len) {
		cnt = n = len;
		int num = n;
		init();
		for (int i = 1; i <= n; ++i) 
			if (in[i] == 0) q2.push(i);
		while (!q2.empty()) {
			int u = q2.top();
			q2.pop();
			order[cnt--] = u;
			ans[u] = num--;
			for (int j = 0; j < (int)g[u].size(); ++j) {
				int v = g[u][j];
				if (--in[v] == 0) q2.push(v);
			}
		}
		return cnt == 0;
	}
}topsort;
int ans[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T, m, n;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) g[i].clear();
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			g[v].push_back(u);
		}
		fill(ans, ans+n+1, 0);
		if (topsort.min_num(n) == 0) cout << -1 << endl;
		else {
			for (int i = 1; i <= n; ++i) {
				if (i > 1) cout << " ";
				cout << topsort.ans[i];
			}
			cout << endl;
		}
	}
	return 0;
}
