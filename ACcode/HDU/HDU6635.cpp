#include <bits/stdc++.h>
const int maxn = 5e4 + 5;
using namespace std;
int a[maxn], b[maxn], c[maxn], d[maxn];
int vis[maxn], used[maxn], path[maxn], n;
int solve() {
    int len = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[a[i]] == -1) continue;
        int it = lower_bound(d, d + len, a[i]) - d;
        if (it == len) {
        	d[len++] = a[i];
        	path[i] = len;
        }else {
        	d[it] = a[i];
        	path[i] = it + 1;
        }
    }
    fill(used, used+maxn, 0);
    int tmp = len;
    for (int i = n; i >= 1; --i) {
    	if (vis[a[i]] == -1) continue;
    	if (path[i] == tmp) used[a[i]] = 1, tmp--;
    }
    return len;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(vis, vis+n+1, 0);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
        c[n] = solve();
        for (int i = n-1; i >= 1; --i) {
        	vis[a[b[i+1]]] = -1;
            if (used[a[b[i+1]]] == 0) c[i] = c[i+1];
            else c[i] = solve();
        }
        for (int i = 1; i <= n; ++i) {
        	if (i > 1) printf(" ");
        	printf("%d", c[i]);
        }
        puts("");
    }
    return 0;
}