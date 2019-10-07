#include <bits/stdc++.h>
using namespace std;
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0,d; i < n; ++i) {
            cin >> d;
            sum += d;
        }
        int ans = sum / n;
        if (sum % n) ans++;
        cout << ans << endl;
    }
    return 0;
}
