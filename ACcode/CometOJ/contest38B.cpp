#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int> > a(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        } 
    }
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (a[0][i] || a[1][i]) {
            l = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; --i) {
        if (a[0][i] || a[1][i]) {
            r = i;
            break;
        }
    }
    if (l == -1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = l+1; i <= r; ++i) {
        if (a[0][i] == 1 && a[1][i] == 0) {
            if (a[0][i-1] == 0) {
                ans++;
                a[1][i] = 1;
            }
        }else if (a[0][i] == 0 && a[1][i] == 1) {
            if (a[1][i-1] == 0) {
                a[0][i] = 1;
                ans++;
            }
        }else if (a[0][i] == 0 && a[1][i] == 0) {
            if (a[0][i-1] + a[1][i-1] == 2) {
                a[0][i] = a[1][i] = 1;
            }else {
                if (a[0][i-1]) {
                    a[0][i] = 1;
                }else {
                    a[1][i] = 1;
                }
            }
            ans++;                
        } 
    }
    cout << ans << endl;
    return 0;
}