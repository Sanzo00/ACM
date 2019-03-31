#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 105;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
    
int a[100005];
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    int last = m * n - sum;
    int ans = 0;
    for (int i = 0; i < n && last > 0; ++i) {
        ans++;
        last -= 1000 - a[i];
    }
    cout << ans << endl;

    return 0;
}