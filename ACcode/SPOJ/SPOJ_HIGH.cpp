#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 105;

LL A[maxn][maxn], B[maxn][maxn];

LL det(int n) {
    LL tmp = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            while (A[j][i]) {
                // LL t = A[i][i] * inv(A[j][i], mod);
                LL t = A[i][i] / A[j][i];
                for (int k = i; k < n; ++k) {
                    A[i][k] = (A[i][k] - t * A[j][k]);
                    // swap(A[i][k], A[j][k]);
                }
                swap(A[i], A[j]);
                tmp *= -1;
            }
        }
        if (!A[i][i]) return 0;
        // tmp = A[i][i] * tmp % mod;
        tmp = A[i][i] * tmp;
    }
    // return (tmp + mod) % mod;
    return tmp;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    int T;
    cin >> T;
    while (T--) {
        mem(B, 0);
        mem(A, 0);
        int n, m;
        cin >> n >> m;
        for (int i = 0, x, y; i < m; ++i) {
            cin >> x >> y;
            x--;
            y--;
            B[x][y]++;
            B[y][x]++;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (B[i][j] == 0) continue;
                A[i][i] += B[i][j];
                A[i][j] = -B[i][j];
            }
        }
        cout << det(n-1) << endl;
    }
    return 0;
}