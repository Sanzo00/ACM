// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
const int maxn = 1e2 + 5;
using namespace std;
vector<int> g[maxn];
struct Topsort{ // 下标1
	priority_queue<int, vector<int>, greater<int> > q1; // 字典序小，正向建图
	priority_queue<int, vector<int> > q2; // 编号小的优先级高，反向建图
	int in[maxn], order[maxn], vis[maxn], n, cnt;
	int unique, inc;
	void init () {
		unique = 1;
		inc = 0;
		fill(in, in+n+1, 0);
		fill(vis, vis+n+1, 0);
		for (int i = 1; i <= 26; ++i) {
			for (int j = 0; j < (int)g[i].size(); ++j) {
				in[g[i][j]]++;
				vis[i] = vis[g[i][j]] = 1;
			}
		}
	}
	int min_lex (int len) {
		n = len;
		cnt = 0;
		init();
		for (int i = 1; i <= 26; ++i) 
			if (vis[i] && in[i] == 0) q1.push(i);
		while (!q1.empty()) {
			if (q1.size() > 1) unique = 0;
			int u = q1.top();
			q1.pop();
			order[++cnt] = u;
			for (int j = 0; j < (int)g[u].size(); ++j) {
				int v = g[u][j];
				in[v]--;
				if (in[v] == 0) q1.push(v);
			}
		}
		for (int i = 1; i <= 26; ++i) {
			if (in[i]) inc = 1;
		}
		return cnt == n;
	}	
	int min_num (int len) {
		cnt = n = len;
		init();
		for (int i = 1; i <= n; ++i) 
			if (in[i] == 0) q2.push(i);
		while (!q2.empty()) {
			int u = q2.top();
			q2.pop();
			order[cnt--] = u;
			for (int j = 0; j < (int)g[u].size(); ++j) {
				int v = g[u][j];
				if (--in[v] == 0) q2.push(v);
			}
		}
		return cnt == 0;
	}
}topsort;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	while (scanf("%d %d", &n, &m), n) {
		for (int i = 1; i <= 26; ++i) g[i].clear();
		int flag = 0;
		char a, b;
		for (int i = 0; i < m; ++i) {
			getchar();
			scanf("%c%c%c", &a, &b, &b);
			a -= 'A'-1, b -= 'A'-1;
			if (flag) continue;
			g[(int)a].push_back(int(b));
			topsort.init();
			int tt = topsort.min_lex(n);
			if (topsort.inc) {
				printf("Inconsistency found after %d relations.\n", i+1);
				flag = 1;
			}else if (tt && topsort.unique) {
				flag = 1;
				printf("Sorted sequence determined after %d relations: ", i+1);
				for (int i = 1; i <= topsort.cnt; ++i) printf("%c", topsort.order[i]+'A'-1);
				puts(".");
			}
		}
		if (flag == 0) puts("Sorted sequence cannot be determined.");
	}
	return 0;
}
