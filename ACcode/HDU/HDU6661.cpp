#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
using namespace std;	
struct SuffixArray{ // 下标
	int cntA[maxn], cntB[maxn], A[maxn], B[maxn];
	int Sa[maxn], tsa[maxn], height[maxn], Rank[maxn];
	int n, dp[maxn][21];
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
	    int len = r - l + 1;
	    int x = log2(len);
	    return min(dp[l][x], dp[r - (1 << x) + 1][x]);
	}
	int lcp(int x, int y) { // 最长公共前缀
		int l = Rank[x];
		int r = Rank[y];
		if (l > r) swap(l, r);
		return rmq(l+1, r);
	}
}L, R;
int work(int l, int r, int p, int len, int k) { // 计算前后缀，前后扩展，累计答案
	int rt = L.lcp(l, r+1); // 向右扩展
	int lt = R.lcp(len+1-r, len+1-l+1); // 向前扩展
	r += rt;
	l -= lt;
	return max(0, r-l+1 - k*p + 1); // 返回kp的个数 
}
char s[maxn], t[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		int k;
		long long ans = 0;
		scanf("%d%s", &k, t+1);
		int len = strlen(t+1);
		if (k == 1) {
			ans = 1ll * (1 + len) * len / 2;
			printf("%lld\n", ans);
			continue;
		}
		strcpy(s+1, t+1);
		reverse(t+1, t+1+len);
		s[0] = t[0] = '&';
		L.init(s, len); L.st();
		R.init(t, len); R.st();

		for (int i = 1; i <= len/2; ++i) { // 枚举循环节
			int last = 1;
			for (int j = i+1; j <= len; j += i) { // 找到最长的循环节为i的字符串
				if (L.lcp(last, j) >= i) continue;
				ans += work(last, j-1, i, len, k);
				if (j+i-1 <= len) last = j;
				else last = 0;
			}
			if (last) ans += work(last, len, i, len, k);
		}
		printf("%lld\n", ans);
	}
	return 0;
}