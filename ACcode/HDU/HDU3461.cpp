#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e7 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int pre[maxn];
int quick(LL a, LL b) {
	LL ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
int find(int x) {
	int tx = x, t;
	while (x != pre[x]) x = pre[x];
	while (pre[tx] != x) {
		t = pre[tx];
		pre[tx] = x;
		tx = t;
	}
	return x;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    while (cin >> n >> m) {
    	int cnt = 0;
    	for (int i = 0; i <= n; ++i) pre[i] = i;
    	for (int i = 0, a, b; i < m; ++i) {
    		cin >> a >> b;
    		a--;
    		int fa = find(a);
    		int fb = find(b);
    		if (fa == fb) continue;
    		pre[fb] = fa;
    		cnt++;
    	}
    	cout << quick(26, n - cnt) << endl;;
    }

    return 0;
}