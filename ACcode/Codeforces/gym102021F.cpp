#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 3e6;
using namespace std;

int f[40];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    map<int, int> mp, where;
    f[1] = f[2] = 1;
    mp[1] = 2;
    for (int i = 3; i < 33; ++i) {
        f[i] = f[i-1] + f[i-2];
        mp[f[i]] = i;
        // cout << f[i] << endl;
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1 && where[a[i]]) where[maxn] = i+1;
        else where[a[i]] = i+1;
    }
    for (int i = 0; i < n; ++i) {
        int t = mp[a[i]];
        if (!t) continue;
        if (a[i] == 1) {
            if (where[maxn] == 0) continue;
            cout << i+1 << " " << where[maxn] << "\n";
            return 0;
        }else {
            int l = f[t-1];
            int r = f[t+1];
            if (where[l]) {
                cout << where[l] << " " << i+1 << "\n";
                return 0;
            }
            if (where[r]) {
                cout << i+1 << " " << where[r] << "\n";
                return 0;
            }
        }
    }
    cout << "impossible\n";
    
    return 0;
}
