#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 2e5 + 5;
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
int pos;
int check (int a, int b) {
	if (a < pos && b > pos) return 0;
	return 1;
}

int main () {
	ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    s[0] = ' ';
    scanf("%s", s+1);
    int len = strlen(s);
    s[len] = '#';
    pos = len;
    scanf("%s", s + len + 1);
    n = strlen(s) - 1;
    SuffixArray();
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
    	int a = Sa[i];
    	int b = Sa[i - 1];
    	if (a > b) swap(a, b);
    	if (height[i] <= ans || check(a, b)) continue;
    	ans = height[i];
    	// ans = max(ans, min(height[i], pos - a));
    }
    cout << ans << endl;
	
	return 0;
}
