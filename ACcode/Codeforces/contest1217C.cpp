#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int L[maxn];
char s[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int lens = strlen(s);
        int tmp = 0;
        fill(L, L+lens+1, 0);
        for (int i = 0; i < lens; ++i) {
            L[i] = tmp;
            if (s[i] == '0') tmp++;
            else tmp = 0;
        }
        long long ans = 0;
 
        for (int i = 0; i < lens; ++i) {
            if (s[i] == '0') continue;
            int tmp = 0;
            for (int j = i; j < lens; ++j) {
                tmp = tmp * 2 + s[j] - '0';
                if (tmp > j-i+1+L[i]) break;
                ans++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}