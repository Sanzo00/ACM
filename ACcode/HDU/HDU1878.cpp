#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
char s[maxn];
vector<int> g[maxn];
struct Euler{
	int in[maxn], out[maxn], pre[maxn], n;
	int cnt;
	int find(int x) {
		int t = x;
		while (x != pre[x]) x = pre[x];
		while (pre[t] != x) {
			int fa = pre[t];
			pre[t] = fa;
			t = fa;
		}
		return x;
	}
	void join(int x, int y) {
		int fx = find(x);
		int fy = find(y);
		if (fx == fy) return;
		pre[fy] = fx;
	}
	void init(int t) {
		n = t; // 下标从1
		cnt = 0;
		fill(in, in+n+1, 0);
		fill(out, out+n+1, 0);
		// fill(vis, vis+n+1, 0);
		for (int i = 1; i <= n; ++i) pre[i] = i;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < (int)g[i].size(); ++j) {
				join(i, g[i][j]);
				out[i]++; in[g[i][j]]++;
			}
		}
		for (int i = 1; i <= n; ++i) { // 判断连通性
			if (find(i) != find(1)) cnt++;
		}
	}
	int direct_circle() { // 有向图欧拉回路：入度-出度 = 0
		if (cnt > 0) return 0;
		for (int i = 1; i <= n; ++i) {
			int t = in[i] - out[i];
			if (t != 0) return 0;
		}
		return 1;
	}
	int direct_oneway() { // 有向图欧拉通路：入度-长度 = -1， 1， 0
		if (cnt > 0) return 0;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; ++i) {
			int t = in[i] - out[i];
			if (fabs(t) > 1) return 0;
			if (t == 1) cnt1++;
			if (t == -1) cnt2++;
			if (cnt1 > 1 || cnt2 > 1) return 0;
		}
		return 1;
	}
	int undirect_circle() { // 度数为偶数 
		if (cnt > 0) return 0;
		for (int i = 1; i <= n; ++i) {
			if ((in[i] + out[i]) & 1) return 0;
		}
		return 1;
	}
	int undirect_oneway() { // 只有两个是奇数
		if (cnt > 0) return 0;
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if ((in[i] + out[i]) & 1) cnt++;
			if (cnt > 2) return 0;
		}
		return 1;
	}
}euler;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	while (scanf("%d", &n), n) {
		scanf("%d", &m);
		for (int i = 1; i <= n; ++i) g[i].clear();
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
		}
		euler.init(n);
		puts(euler.undirect_circle() ? "1" : "0");
	}
	return 0;
}