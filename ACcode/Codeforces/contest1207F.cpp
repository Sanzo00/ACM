#include <bits/stdc++.h>
const int maxn = 5e5 + 5;
using namespace std;
long long ans[705][705], a[maxn];
int main() {
    int q;
    cin >> q;
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            a[x] += y;
            for (int i = 1; i <= 700; ++i) {
                ans[i][x % i] += y;
            }
        }else {
            if (x <= 700) cout << ans[x][y] << endl;
            else {
                int sum = 0;
                for (int i = y; i < maxn; i += x) {
                    sum += a[i];
                }
                cout << sum << endl;
            }
        }
    }
    return 0;
}
