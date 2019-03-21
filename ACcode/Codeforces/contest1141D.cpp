#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 200005;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    
    string l, r;
    int n;
    while (cin >> n >> l >> r) {
        vector<int> g1[1000], g2[1000];
        set<P> ans;
        for (int i = 0; i < n; ++i) {
            g1[l[i]].push_back(i);
        }
        vector<int> wen;
        vector<int> left;
        for (int i = 0; i < n; ++i) {
            if (r[i] == '?') {
                wen.push_back(i);
                continue;
            }
            int t = r[i];
            if (g1[t].size()) {
                ans.insert(P(g1[t][0],i));
                g1[t].erase(g1[t].begin());
            }else {
                left.push_back(i);
            }
        }
        int t = min(g1['?'].size(), left.size());
        for (int i = 0; i < t; ++i) {
            ans.insert(P(g1['?'][i], left[i]));
        }
        int t2 = wen.size();
        for (int i = 0; i < 1000 && t2; ++i) {
            if (i == '?' || g1[i].size() == 0) continue;
            for (int k = 0; k < (int)g1[i].size() && t2; ++k) {
                ans.insert(P(g1[i][k], wen[--t2]));
            }
        }
        for (int i = t; i < g1['?'].size() && t2; ++i) {
            ans.insert(P(g1['?'][i], --t2));
        }
        cout << ans.size() << endl;
        for (auto it : ans) {
            cout << it.first+1 << " " << it.second+1 << endl;
        }

    }

    return 0;
}