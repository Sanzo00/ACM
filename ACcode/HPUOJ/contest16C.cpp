#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 10001;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int n, m;
int sum[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    int T;
    cin >> T;
    while (T--) {
        mem(sum, 0);
        cin >> n >> m;
        for (int i = 0, x, y; i < m; ++i) {
            cin >> x >> y;
            sum[x+y-1]++;
        }

        int flag = 1;
        for (int i = 1; i <= n; ++i) {
            if (sum[i] == i) flag = 0;
        }

        if (flag) cout << "Yes " << 2*n - 2 << endl;
        else cout << "No\n";
    }

    return 0;
}