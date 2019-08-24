#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
char s[maxn];
struct Tree{
	int tot, rt[maxn], lson[maxn*20], rson[maxn*20], cnt[maxn*20];
	int build (int l, int r) {
		int o = ++tot;
		int mid = (l + r) >> 1;
		cnt[o] = 0;
		if (l != r) {
			lson[o] = build(l, mid);
			rson[o] = build(mid+1, r);
		}
		return o;
	}
	int update(int prev, int l, int r, int v) {
		int o = ++tot;
		int mid = (l + r) >> 1;
		lson[o] = lson[prev];
		rson[o] = rson[prev];
		cnt[o] = cnt[prev] + 1;
		if (l != r) {
			if (v <= mid) lson[o] = update(lson[o], l, mid, v);
			else rson[o] = update(rson[o], mid+1, r, v);
		}
		return o;
	}
	int query(int u, int v, int l, int r, int k) {
		if (l == r) return l;
		int mid = (l + r) >> 1;
		int num = cnt[lson[v]] - cnt[lson[u]];
		if (num >= k) return query(lson[u], lson[v], l, mid, k);
		else return query(rson[u], rson[v], mid+1, r, k-num);
	}
};
struct SuffixArray{ // 下标1
	int cntA[maxn], cntB[maxn], A[maxn], B[maxn];
	int Sa[maxn], tsa[maxn], height[maxn], Rank[maxn]; // Sa[i] 排名第i的下标， Rank[i] 下标i的排名
	int n, dp[maxn][18];
	Tree T;
	void build() {
		T.tot = 0;
		T.rt[0] = T.build(1, n);
		for (int i = 1; i <= n; ++i) T.rt[i] = T.update(T.rt[i-1], 1, n, Sa[i]);
	}
	void init(char *buf, int len) { // 预处理，sa，rank，height
		n = len;
		for (int i = 0; i < 128; ++i) cntA[i] = 0;
		for (int i = 1; i <= n; ++i) cntA[(int)buf[i]]++;
		for (int i = 1; i < 128; ++i) cntA[i] += cntA[i-1];
		for (int i = n; i >= 1; --i) Sa[ cntA[(int)buf[i]]-- ] = i;
		Rank[ Sa[1] ] = 1;
		for (int i = 2; i <= n; ++i) {
			Rank[Sa[i]] = Rank[Sa[i-1]];
			if (buf[Sa[i]] != buf[Sa[i-1]]) Rank[Sa[i]]++;
		}
		for (int l = 1; Rank[Sa[n]] < n; l <<= 1) {
			for (int i = 0; i <= n; ++i) cntA[i] = 0;
			for (int i = 0; i <= n; ++i) cntB[i] = 0;
			for (int i = 1; i <= n; ++i) {
				cntA[ A[i] = Rank[i] ]++;
				cntB[ B[i] = (i + l <= n) ? Rank[i+l] : 0]++;
			}
			for (int i = 1; i <= n; ++i) cntB[i] += cntB[i-1];
			for (int i = n; i >= 1; --i) tsa[ cntB[B[i]]-- ] = i;
			for (int i = 1; i <= n; ++i) cntA[i] += cntA[i-1];
			for (int i = n; i >= 1; --i) Sa[ cntA[A[tsa[i]]]-- ] = tsa[i];
			Rank[ Sa[1] ] = 1;
			for (int i = 2; i <= n; ++i) {
				Rank[Sa[i]] = Rank[Sa[i-1]];
				if (A[Sa[i]] != A[Sa[i-1]] || B[Sa[i]] != B[Sa[i-1]]) Rank[Sa[i]]++;
			}
		}
		for (int i = 1, j = 0; i <= n; ++i) {
			if (j) --j;
			int tmp = Sa[Rank[i] - 1];
			while (i + j <= n && tmp + j <= n && buf[i+j] == buf[tmp+j]) ++j;
			height[Rank[i]] = j;
		}
	}
	void st() {
		for (int i = 1; i <= n; ++i) {
	        dp[i][0] = height[i];
	    }
	    for (int j = 1; j <= log2(n); ++j) {
		    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
		        dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		    }
		}
	}
	int rmq(int l, int r) {
		if (l == r) return inf;
		l++;
	    int len = r - l + 1;
	    int x = log2(len);
	    return min(dp[l][x], dp[r - (1 << x) + 1][x]);
	}
	int findl(int pos, int len) {
		int l = 1, r = pos;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (rmq(mid, pos) < len) l = mid + 1;
			else r = mid - 1;
		}
		return l;
	}
	int findr(int pos, int len) {
		int l = pos, r = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (rmq(pos, mid) < len) r = mid - 1;
			else l = mid + 1;
		}
		return r;
	}
	int solve(int ql, int qr, int k) {
		int len = qr - ql + 1;
		int pos = Rank[ql];
		int l = findl(pos, len);
		int r = findr(pos, len);
		if (r - l + 1 < k) return -1;
		return T.query(T.rt[l-1], T.rt[r], 1, n, k);
	}
}S;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		scanf("%s", s+1);
		S.init(s, strlen(s+1));
		S.st();
		S.build();
		int l, r, k;
		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &l, &r, &k);
			printf("%d\n", S.solve(l, r, k));
		} 
	}
	return 0;
}