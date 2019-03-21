#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 2250005;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

map<int, vector<P> > all;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i] += a[i-1];
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = i; j >= 1; --j) {
                int tmp = a[i] - a[j-1];
                if (all[tmp].size() && all[tmp].back().second >= j) continue;
                all[tmp].emplace_back(P(j, i));
            }
        }
        vector<P> ans;
        for (auto it : all) {
            if (it.second.size() > ans.size()) ans = it.second;
        }
        cout << ans.size() << endl;
        for (auto it : ans) {
            cout << it.first << " " << it.second << endl; 
        }
    }

    return 0;
}