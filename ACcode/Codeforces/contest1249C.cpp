#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
unsigned long long a[maxn], b[maxn];
int main() {
    a[0] = 1;
    b[0] = 1;
    for (int i = 1; i <= 38; ++i) a[i] = a[i-1] * 3, b[i] = a[i] + b[i-1];
    int q;
    unsigned long long n, ans;
    cin >> q;
    while (q--) {
        cin >> n;
        ans = 0;
        for (int i = 38; i >= 0; --i) {
            if (b[i-1] < n || i == 0) {
                ans += a[i];
                if (a[i] >= n) break;
                n -= a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}