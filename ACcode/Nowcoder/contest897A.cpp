#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        vector<int> a(6);
        map<int,int> mp;
        int n = 6;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            if (mp[a[i]] == 1) {
                cout << a[i] << endl;
                break;
            }
        }
    }
  
    return 0;
}