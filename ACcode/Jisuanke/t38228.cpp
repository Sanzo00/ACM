#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 5e5 + 5;
  
int a[maxn];	 
int dp[maxn][20];
LL pre[maxn], suf[maxn];
void ST(int n) {
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = a[i];
	}
	for (int j = 1; j <= log2(n); ++j) {
		for (int i = 1; i+(1<<j)-1 <= n; ++i) {
			dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
		}
	}
}
LL RMQ(int l, int r) {
	int len = r - l + 1;
	int x = log2(len);
	return min(dp[l][x], dp[r - (1<<x)+1][x]);
}

class Seg{
	LL Max[maxn<<2], Min[maxn<<2];
	public: void build(int rt, int l, int r, LL a[]) {
	 	if (l == r) {
			Max[rt] = a[l];
			Min[rt] = a[l];
			return;
		}
		build(lc, l, mid, a);
		build(rc, mid+1, r, a);
		Max[rt] = max(Max[lc], Max[rc]);
		Min[rt] = min(Min[lc], Min[rc]);	
	}

	public: LL query_min(int rt, int l, int r, int ql, int qr) {
			if (r < ql || l > qr) return 1e18;
			if (l >= ql && r <= qr) return Min[rt];
			LL tmp1 = query_min(lc, l, mid, ql, qr);
			LL tmp2 = query_min(rc, mid+1, r, ql, qr);
			return min(tmp1, tmp2);
	}
	public: LL query_max(int rt, int l, int r, int ql, int qr) {
			if (r < ql || l > qr) return -1e18;
			if (l >= ql && r <= qr) return Max[rt];
			LL tmp1 = query_max(lc, l, mid, ql, qr);
			LL tmp2 = query_max(rc, mid+1, r, ql, qr);
			return max(tmp1, tmp2);
	}		
}Pre, Suf;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
  
    int n;
    scanf("%d", &n); 
    for (int i = 1; i <= n; ++i) {
    	scanf("%d", &a[i]);
    	pre[i] = pre[i-1] + a[i];
    }
    for (int i = n; i >= 1; --i) {
    	suf[i] = suf[i+1] + a[i];
    }
    ST(n);
    Pre.build(1, 1, n, pre);
    Suf.build(1, 1, n, suf);
    LL ans = -1e18;
    for (int i = 1; i <= n; ++i) {
    	int left, right, l = i, r = n;
    	while (l <= r) {
    		if (RMQ(l, mid) < a[i]) r = mid - 1;
    		else l = mid + 1;
    	}
    	right = r;

    	l = 1, r = i;
    	while (l <= r) {
    		if (RMQ(mid, r) < a[i]) l = mid + 1;
    		else r = mid - 1;
    	}
    	left = l;
    	if (a[i] >= 0) {
    		LL R = Pre.query_max(1, 1, n, i, right);
    		LL L = Suf.query_max(1, 1, n, left, i);
    		ans = max(ans, (R - pre[i-1] + L - suf[i]) * a[i]);
    		
    	}else {
    		LL R = Pre.query_min(1, 1, n, i, right);
    		LL L = Suf.query_min(1, 1, n, left, i);
    		ans = max(ans, (R - pre[i-1] + L - suf[i]) * a[i]);
    	}
    }
    cout << ans << endl;
    return 0;
}