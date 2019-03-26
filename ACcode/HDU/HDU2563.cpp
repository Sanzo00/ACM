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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    int O[30], U[30];
    O[1] = 2;
    U[1] = 1;
    for (int i = 2; i <= 20; ++i) {
        O[i] = 2 * U[i-1] + O[i-1];
        U[i] = U[i-1] + O[i-1];
    }
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << O[n] + U[n] << endl;
    }

    return 0;
}