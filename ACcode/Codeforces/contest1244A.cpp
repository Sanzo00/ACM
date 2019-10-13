#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int h, w;
        h = a / c;
        w = b / d;
        if (a % c) h++;
        if (b % d) w++;
        if (h + w > k) cout << -1 << endl;
        else cout << h << " " << w << endl;
    }
 
    return 0;
}