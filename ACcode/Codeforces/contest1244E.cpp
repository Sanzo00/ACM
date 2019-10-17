#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
long long a[maxn];
int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    sort(a+1, a+1+n);
    long long ans = a[n] - a[1];
    for (int i = 2; i <= (n+1)/2; ++i) {
        long long down = a[i] - a[i-1] + a[n+2-i] - a[n+1-i];
        down = min(down, k / (i-1));
        ans -= down;
        k -= down * (i-1);
    }
    if (n % 2 == 0) {
        long long down = a[n/2+1] - a[n/2];
        down = min(down, k / (n/2));
        ans -= down;
        k -= down * (n/2);
    }
    printf("%lld\n", ans);
    return 0;
}
