#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 2e5 + 7;
 
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
     
    int n;
    int ans, cnt = 0;;
    cin >> n;
    map<int,int> mp;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        mp[x]++;
        if (mp[x] > cnt) {
            cnt = mp[x];
            ans = x;
        }
 
    }
 
    cout << ans << endl;
    return 0;
}