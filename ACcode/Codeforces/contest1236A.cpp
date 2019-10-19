#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        for (int i = 0; i <= 100; ++i) {
            for (int j = 0; j <= 100; ++j) {
                int tmp = 0, ta = a, tb = b, tc = c;
                if (ta >= i && tb >= 2*i && (tb - 2*i) >= j && (tc >= j*2)) ans = max(ans, i*3 + j*3);
            }
        }
        cout << ans << endl;
    }
 
    return 0;
}