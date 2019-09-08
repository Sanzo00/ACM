#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, c;
        scanf("%d%d%d",&a, &b, &c);
        int t = min(a, b);
        if (a + c <= b) {
            printf("0\n");
            continue;
        }
        int ans = (c + b - a);
        if (ans < 0) ans = -2;
        ans = ans / 2 + 1;
        ans = c - ans + 1;
        printf("%d\n", ans);
    }
    return 0;
}