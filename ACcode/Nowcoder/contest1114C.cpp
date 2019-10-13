#include <bits/stdc++.h>
const int maxn = 1e3 + 5;
using namespace std;
bitset<maxn> b[maxn][2];
char s[maxn];
int main() {
    int n, m, q;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        for (int j = 0; j < m; ++j) {
            b[j][s[j]-'0'].set(i);
        }
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%s", s);
        bitset<maxn> a;
        a.flip();
        for (int i = 0; i < m; ++i) {
            if (s[i] == '_') continue;
            a &= b[i][s[i]-'0'];
            // cout << a << endl;
        }
        int ans = a.count();
        printf("%d\n", ans);
    }
    return 0;
}