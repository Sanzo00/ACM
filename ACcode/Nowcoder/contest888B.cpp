#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
int pos[maxn], a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    scanf("%d", &n);
    long long ans = 0, tmp = 0;
 
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        tmp += i;
        tmp -= pos[a[i]];
        ans += tmp;
        pos[a[i]] = i;
    }
    cout << ans << endl;
    return 0;
}