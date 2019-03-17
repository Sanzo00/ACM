#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 1044373;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
int cnt = 0;
int judge(int x) {
    if (x == 1) return 1;
    if (cnt++ >= 20) return 0;
    int sum = 0;
    while (x) {
        sum += (x%10) * (x%10);
        x /= 10;
    } 
    return judge(sum);
}
map<int, int> mi;

int main() {
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    scanf("%d", &q);
    int now = 0;
    for (int i = 1; now < 150000; ++i) {
        cnt = 0;
        if (judge(i)) mi[++now] = i;
    }
    while (q--) {
        int d;
        scanf("%d", &d);
        printf("%d\n", mi[d]);
    }
    
    return 0;
}