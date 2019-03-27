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

int mod;
LL A[maxn][maxn];

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
    int n;
    while (cin >> n >> mod) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> A[i][j];
            }
        }
        LL ans = det(n);

        cout << ans << endl;
    }


    return 0;
}