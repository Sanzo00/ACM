#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 1000001;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

char a[101][101];
int R[101][91], C[101][91];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) 
            scanf("%s", a[i]);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mem(R, 0);
                mem(C, 0);
                int c = m;
                for (int p = i; p < n; ++p) {
                    for (int k = j; k < c; ++k) {
                        int t = a[p][k];
                        if (R[p][t] || C[k][t]) {
                            c = k;
                            break;
                        }
                        ans = max(ans, (p-i+1)*(k-j+1));
                        R[p][t] = 1;
                        C[k][t] = 1;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}