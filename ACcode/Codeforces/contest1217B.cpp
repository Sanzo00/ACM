#include <bits/stdc++.h>
using namespace std;
struct ac{
    long long x, y;
}a[120];
bool cmp(ac t1, ac t2) {
    return (t1.x - t1.y) > (t2.x - t2.y);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, x;
        scanf("%d%d", &n, &x);
        long long tmp = 0;
        for (int i = 0; i < n; ++i) scanf("%lld %lld", &a[i].x, &a[i].y), tmp = max(tmp, a[i].x);
        sort(a, a+n, cmp);
        x -= tmp;
        if (a[0].y >= a[0].x && x > 0) {
            puts("-1");
            continue;
        }
        if (x <= 0) {
            puts("1");
            continue;
        }
        long long t = a[0].x - a[0].y;
        long long ans = (x + t-1) / t + 1;
        printf("%lld\n", ans);
    }
    return 0;
}