#include <bits/stdc++.h>
const int maxn = 7e3 + 5;
using namespace std;
long long a[maxn], b[maxn];
map<long long, int> mp;
int ok[maxn];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        mp[a[i]]++;
    } 
    for (int i = 1; i <= n; ++i)  scanf("%lld", &b[i]);
    for (int i = 1; i <= n; ++i) {
        if (mp[a[i]] <= 1) continue;
        for (int j = 1; j <= n; ++j) {
            if ((a[i] & a[j]) == a[j]) ok[j] = 1;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans += ok[i] ? b[i] : 0;
    cout << ans << endl;
    return 0;
}
