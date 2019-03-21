#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 1044373;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, m;
    cin >> n >> m;
    LL t = m / n;

    if (m % n) {
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;
    while (t % 2 == 0) {
        cnt += 1;
        t /= 2;
    }

    while (t % 3 == 0) {
        cnt += 1;
        t /= 3;
    }
    if (t > 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << cnt << endl;
    return 0;
}