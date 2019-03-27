#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 205;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int mod = 1e9;
LL A[maxn][maxn], B[maxn][maxn];
char g[maxn][maxn];
int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
LL det(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            A[i][j] = (A[i][j] % mod + mod) % mod;
        }
    }
    LL tmp = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            while (A[j][i]) {
                LL t = A[i][i] / A[j][i];
                for (int k = i; k <= n; ++k) {
                    A[i][k] = (A[i][k] - t * A[j][k]) % mod;
                    swap(A[i][k], A[j][k]);
                }
                tmp *= -1;
            }
        }
        if (!A[i][i]) return 0;
        tmp = A[i][i] * tmp % mod;
    }
    return (tmp + mod) % mod;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    int n, m;
    while (cin >> n >> m) {
        mem(A, 0);
        mem(B, 0);
        map<P,int> mp;
        int now = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> g[i][j];
                if (g[i][j] == '*') continue;
                mp[P(i,j)] = ++now;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int l = mp[P(i,j)];
                for (int k = 0, x, y; k < 4; ++k) {
                    if (g[i][j] == '*') continue;
                    x = i + d[k][0];
                    y = j + d[k][1];
                    if (x < 1 || y < 1 || x > n || y > m) continue;
                    if (g[x][y] == '*') continue;
                    int r = mp[P(x, y)];
                    B[l][r] = B[r][l] = 1;                    
                }
            }
        }

        for (int i = 1; i <= now; ++i) {
            for (int j = 1; j <= now; ++j) {
                if (i == j) continue;
                if (!B[i][j]) continue;
                A[i][i]++;
                A[i][j] = -1;
            }
        }
        LL ans = det(now-1);
        cout << ans << endl;
    }


    return 0;
}