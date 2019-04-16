#include <bits/stdc++.h>
#define LL long long
#define uLL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 2003;
LL a[maxn][maxn], b[maxn][maxn], c[maxn][maxn], d[maxn][maxn];
LL pow1[maxn], pow2[maxn];
int  t1[maxn][maxn], t2[maxn][maxn];
const LL seed1 = 805306457;
const LL seed2 = 402653189; 
const LL mod = 1e9 + 7;

int n, m;
void init() {
	pow2[0] = pow1[0] = 1;
    for (int i = 1; i <= n; ++i) {
    	pow1[i] = pow1[i-1] * seed1 % mod;
    	pow2[i] = pow2[i-1] * seed2 % mod;
    }
}
void solve(LL x[][maxn], int y) {
	for (int i = 1; i <= y; ++i) {
		for (int j = 1; j <= y; ++j) {
			x[i][j] = (x[i][j] + x[i][j-1] * seed1) % mod;
		}
		for (int j = 1; j <= y; ++j) {
			x[i][j] = (x[i][j] + x[i-1][j] * seed2) % mod;
		}
	}
}
void print(LL x[][maxn], int l, int r) {
	for (int i = 1; i <= l; ++i) {
		for (int j = 1; j <= r; ++j) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}
int sum[maxn][maxn];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		cin >> t1[i][j];
    	}
    }
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		a[i][j] = (t1[i][j+1] - t1[i][j] + mod) % mod;
    		b[j][i] = (t1[j+1][i] - t1[j][i] + mod) % mod;
    	}
    }
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		cin >> t2[i][j];
    	}
    }
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		c[i][j] = (t2[i][j+1] - t2[i][j] + mod) % mod;
    		d[j][i] = (t2[j+1][i] - t2[j][i] + mod) % mod;
    	}
    }
    init();
    solve(a, n);
    solve(b, n);
    solve(c, m);
    solve(d, m);    
    for (int i = m; i <= n; ++i) {
    	for (int j = m-1; j <= n-1; ++j) {
    		LL tmp = a[i][j];
    		tmp = (tmp - a[i-m][j] * pow2[m] % mod + mod) % mod;
    		tmp = (tmp - a[i][j-m+1] * pow1[m-1] % mod + mod) % mod;
    		tmp = (tmp + (a[i-m][j-m+1] * pow1[m-1] % mod) * pow2[m] % mod) % mod;
    		if (tmp == c[m][m-1]) sum[i-m][j-m+1]++;
    	}
    }
    for (int i = m-1; i <= n-1; ++i) {
    	for (int j = m; j <= n; ++j) {
    		LL tmp = b[i][j];
    		tmp = (tmp - b[i-m+1][j] * pow2[m-1] % mod + mod) % mod;
    		tmp = (tmp - b[i][j-m] * pow1[m] % mod + mod) % mod;
    		tmp = (tmp + (b[i-m+1][j-m] * pow1[m] % mod) * pow2[m-1] % mod) % mod;
    		if (tmp == d[m-1][m]) sum[i-m+1][j-m]++;
    	}
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
    	for (int j = 0; j <= n; ++j) {
    		if (sum[i][j] == 2) ans++;
    	}
    }
    cout << ans << endl;

    return 0;
}