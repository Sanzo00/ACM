#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        int cnt = 1;
        for (int i = 1; i < (int)a.size(); ++i) if (a[i] != a[i-1]+1) cnt++;
        int ans = 0;
        if (cnt == (int)a.size()) ans = 1;
        else ans = 2;
        cout << ans << endl;
    }
    return 0;
}