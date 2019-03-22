#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 200005;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

char g[506][506];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j];
        }
    }
    
    int ans = 0;

    for (int i = 2; i < n; ++i) {
        for (int j = 2; j < m; ++j) {
            if (g[i][j] == '.') ans++;
        }
    }

    int flag = 0;
    for (int i = 2; i < n; ++i) {
        if (g[i][1] == '#') flag = 1;
        if (g[i][m] == '#') flag = 1;
    }
    for (int i = 2; i < m; ++i) {
        if (g[1][i] == '#') flag = 1;
        if (g[n][i] == '#') flag = 1;
    }
    ans += (flag != 1);

    if (n <= 2) {
        ans = 0;
        for (int i = 2; i < m; ++i) {
            if (n == 2 && g[2][i] == '#') continue;
            if (g[1][i] == '#') continue;
            ans++;
        }
    }else if (m <= 2) {
        ans = 0;
        for (int i = 2; i < n; ++i) {
            if (g[i][1] == '#') continue;
            if (m == 2 && g[i][2] == '#') continue;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}