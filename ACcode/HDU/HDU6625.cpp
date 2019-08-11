#include <bits/stdc++.h>
const int maxn = 3e6 + 5;
using namespace std;
struct Trie{
	int nex[maxn][2], cnt[maxn], end[maxn];
	int p, root; // root = 0
	int newnode() {
		memset(nex[p], 0, sizeof(nex[p]));
		cnt[p] = end[p] = 0;
		return p++;
	}
	void init() {
		p = 0;
		root = newnode();
	}
	void add(int x) {
		int now = root;
		for (int i = 29; i >= 0; --i) {
			int t = (x >> i) & 1;
			if (!nex[now][t]) nex[now][t] = newnode();
			now = nex[now][t];
			++cnt[now];
		}
		end[now] = 1;
	}
}A, B;
vector<int> ans;
void dfs(int r1, int r2, int x) {
	int t = min(A.cnt[r1], B.cnt[r2]);
	A.cnt[r1] -= t;
	B.cnt[r2] -= t;
	if (A.end[r1]) {
		for (int i = 0; i < t; ++i) ans.push_back(x);
		return;
	}
	int a0 = A.nex[r1][0];
	int a1 = A.nex[r1][1];
	int b0 = B.nex[r2][0];
	int b1 = B.nex[r2][1];
	if (A.cnt[a0] && B.cnt[b0]) dfs(a0, b0, x << 1);
	if (A.cnt[a1] && B.cnt[b1]) dfs(a1, b1, x << 1);
	if (A.cnt[a0] && B.cnt[b1]) dfs(a0, b1, x << 1 | 1);
	if (A.cnt[a1] && B.cnt[b0]) dfs(a1, b0, x << 1 | 1);
	return ;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, num;
		scanf("%d", &n);
		A.init();
		B.init();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &num);
			A.add(num);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &num);
			B.add(num);
		}
		ans.clear();
		dfs(A.root, B.root, 0);
		sort(ans.begin(), ans.end());
		for (int i = 0; i < n; ++i) {
			if (i > 0) printf(" ");
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}