#include <bits/stdc++.h>
#define LL  long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define maxn 1000030
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

set<int> all;
int vis[maxn], prime[maxn];
int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int len = 0;
    for (LL i = 2; i < maxn; ++i) {
    	if (vis[i]) continue;
    	all.insert(i);
    	prime[len++] = i;
    	for (LL j = i * i; j < maxn; j += i) {
    		vis[j] = 1;
    	}
    }
    int x;
    while (cin >> x) {
    	int ans = 0;
    	while (x >= 4) {
    		for (int i = 0; i < len; ++i) {
    			if (x - prime[i] < prime[i]) break;
    			if (all.find(x-prime[i]) != all.end() && (x - prime[i]*2) % 2 == 0) {
    				ans++;
    				x = x - prime[i] * 2;
    				break;
    			}
    		}
    	}
    	cout << ans << endl;
    }	

    return 0;
}
