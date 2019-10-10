#include <bits/stdc++.h>
const int maxn = 3e5 + 5;
using namespace std;
char s[maxn];
int main() {
    int n;
    scanf("%d%s", &n, s);
    long long ans = n * (n-1) / 2;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i-1]) {
            ans -= cnt;
            cnt = 1;
        }else {
            cnt++;
        }
    }
    cnt = 1;
    for (int i = n-2; i >= 0; --i) {
        if (s[i] != s[i+1]) {
            ans -= cnt - 1;
            cnt = 1;
        }else {
            cnt++;
        }
    }
    printf("%lld\n", ans);
	return 0;
}

