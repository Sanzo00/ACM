#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 105;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

LL A[maxn][maxn], B[maxn][maxn];

LL det(int n) {
    LL tmp = 1;
    for (int i = 1; i <= n; ++i) {
        if (!A[i][i]) {
            int flag = 1;
            for (int j = i + 1; j <= n; ++j) {
                if (!A[j][i]) continue;
                flag = 0;
                for (int k = i; k <= n; ++k) {
                    swap(A[i][k], A[j][k]);
                }
                tmp *= -1;
                break;
            }
            if (flag) return 0;
        }

        for (int j = i + 1; j <= n; ++j) {
            while (A[j][i]) {
                LL t = A[i][i] / A[j][i];
                for (int k = i; k <= n; ++k) {
                    A[i][k] -= t * A[j][k];
                    swap(A[i][k], A[j][k]);
                }
                tmp *= -1;
            }
        }
        tmp *= A[i][i];
    }
    return tmp;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    int n, m, k;
    while (cin >> n >> m >> k) {
        mem(A, 0);
        mem(B, 0);
        for (int i = 0, x, y; i < m; ++i) {
            cin >> x >> y;
            B[x][y] = B[y][x] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) continue;
                if (!B[i][j]) {
                    A[i][i]++;
                    A[i][j] = -1;
                }
            }
        }
        LL ans = det(n-1);
        cout << ans << endl;
    }

    return 0;
}