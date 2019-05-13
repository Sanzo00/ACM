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
int s[maxn];
int n, k;
void suffixArray () {
	for (int i = 0; i < 256; ++i) cntA[i] = 0;
	for (int i = 1; i <= n; ++i) cntA[s[i]]++;
	for (int i = 1; i < 256; ++i) cntA[i] += cntA[i-1];
	for (int i = n; i >= 1; --i) Sa[ cntA[s[i]]-- ] = i;
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
int check(int x) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (height[i] >= x) cnt++;
		else {
			if (cnt >= k) return 1;
			cnt = 0;
		}
	}
	return 0;
}
int main () {
	ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	cin >> n >> k;
	k--;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	suffixArray();
	int l = 1, r = n;
	while (l <= r) {
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r << endl;
	return 0;
}
