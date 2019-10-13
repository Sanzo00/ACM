#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int f = -1, l = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                l = i;
                if (f == -1) f = i;
            }
        }
        if (f == -1) {
            cout << n << endl;
            continue;
        }
        int ans = 0;
        int t = l + 1;
        t += max(l+1, n-l);
        ans = max(ans, t);
        t = n - f;
        t += max(f+1, n-f);
        ans = max(ans, t);
        cout << ans << endl;
    }
 
    return 0;
}