#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 515;
int T, n;
string s;
int dfs(int x, int d) {
    if (x < 0 || x >= n) return 0;
    if (s[x] == '#') return 0;
    if (s[x] == 'o') return 1;
    if (s[x] == 's' || s[x] == 'e') return 1;
    return dfs(x+d, d);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    freopen("portals.in", "r", stdin);
    cin >> T;
    while (T--) {
        cin >> n >> s;
        s = "#" + s + "#";
        n += 2;
        int u, v;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 's') u = i;
            if (s[i] == 'e') v = i;
        }
        int nu = dfs(u-1, -1) + dfs(u+1, 1);
        int nv = dfs(v-1, -1) + dfs(v+1, 1);
        int ans = 1e9;
        if (s[u-1] == 'o' || s[u+1] == 'o' || s[u-1] == 'e' || s[u+1] == 'e') nu = 1e9;
        if (s[v-1] == 'o' || s[v+1] == 'o' || s[v-1] == 's' || s[v+1] == 's') nv = 1e9;
    
        ans = min(nu, nv);
        if (ans == 1e9) ans = -1;
        cout << ans << endl; 
    }

    return 0;
}