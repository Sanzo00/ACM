#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int cntA[maxn], cntB[maxn], A[maxn], B[maxn];
int Sa[maxn], tsa[maxn], height[maxn], Rank[maxn];
char s[maxn];
int n;
void SuffixArray () {
	for (int i = 0; i < 1000; ++i) cntA[i] = 0;
	for (int i = 1; i <= n; ++i) cntA[(int)s[i]]++;
	for (int i = 1; i < 1000; ++i) cntA[i] += cntA[i-1];
	for (int i = n; i >= 1; --i) Sa[ cntA[(int)s[i]]-- ] = i;
	Rank[ Sa[1] ] = 1;
	for (int i = 2; i <= n; ++i) {
		Rank[Sa[i]] = Rank[Sa[i-1]];
		if (s[Sa[i]] != s[Sa[i-1]]) Rank[Sa[i]]++;
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
		while (i + j <= n && tmp + j <= n && s[i+j] == s[tmp+j]) ++j;
		height[Rank[i]] = j;
	}
}
int dp[maxn][20];
void ST(int n) {
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = height[i];
    }
    for (int j = 1; j <= log2(n); ++j) {
	    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
	        dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
	    }
	}
}
int RMQ(int l, int r) {
    int len = r - l + 1;
    int x = log2(len);
    return min(dp[l][x], dp[r - (1 << x) + 1][x]);
}

int lcp(int x, int y) {
	int l = Rank[x];
	int r = Rank[y];
	if (l > r) swap(l, r);
	return RMQ(l+1, r);
}
int main () {
	ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    s[0] = ' ';
    scanf("%s", s+1);
    n = strlen(s) - 1;
    SuffixArray();
    ST(n);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j + i <= n; j += i) {
    		int tmp = lcp(j, i + j);
    		ans = max(ans, tmp / i + 1);
    		if (j - i + tmp % i >= 1) {
    			ans = max(ans, lcp(j-i+tmp%i, j+tmp%i) / i + 1);
    		}
    	}
    }
    cout << ans << endl;

	return 0;
}
