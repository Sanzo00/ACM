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

LL a[maxn], b[maxn];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    while (cin >> n) {

        LL tmp = 0;

        for (int i = 1; i < n; ++i) {
            cin >> a[i];
            a[i] += a[i - 1];
            b[i] = a[i];
            tmp = min(tmp, a[i]);
        }
        
        sort(b, b + n);
        
        for (int i = 1; i < n; ++i) {
            if (b[i] - b[i-1] != 1) {
                cout << -1 << endl;
                return 0;
            }
        }

        tmp = 1 - tmp;
        for (int i = 0; i < n; ++i) {
            cout << a[i] + tmp << " ";
        }
        cout << endl;

    }
    return 0;
}