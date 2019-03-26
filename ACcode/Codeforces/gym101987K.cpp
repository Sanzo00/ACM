#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 10005;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int n, k, d;
char c;
vector<int> g[maxn];
int vis[maxn], temp[maxn], len;

int other(int x) {
    return (x & 1) ? x+1 : x-1;
}

int dfs(int x) {
    if (vis[other(x)]) return 0;
    if (vis[x]) return 1;
    temp[len++] = x;
    vis[x] = 1;
    for (int i = 0, y; i < (int)g[x].size(); ++i) {
        y = g[x][i];
        if (dfs(y) == 0) return 0;
    }
    return 1;
}

int Twosat() {

    for (int i = 1; i <= n; ++i) {
        if (vis[i*2] || vis[i*2-1]) continue;
        if (dfs(i*2-1) == 0) {
            for (int j = 0; j < len; ++j) {
                vis[temp[j]] = 0;
            }
            len = 0;
            if (dfs(i*2) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   

    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int tmp[3];
        for (int j = 0; j < 3; ++j) {
            cin >> d >> c;
            tmp[j] = d * 2 - (c == 'R');
        }
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j == k) continue;
                g[other(tmp[j])].emplace_back(tmp[k]);
            }
        }

    }
    
    if (Twosat()) {
        for (int i = 1; i <= n; ++i) {
            if (vis[i*2-1]) cout << "R";
            else cout << "B";
        }
        cout << endl;
    }else cout << -1 << endl;
        

    return 0;
}