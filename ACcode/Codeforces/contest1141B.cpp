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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    while (cin >> n) {
        
        vector<int> v(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        
        int ans = 0, cnt = 0;

        for (int i = 0; i < 2*n; ++i) {
            if (v[i % n]) cnt++;
            else {
                ans = max(cnt, ans);
                cnt = 0;
            }
        }
        
        cout << ans << endl;
        
    }

    return 0;
}