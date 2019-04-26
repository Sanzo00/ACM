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
bool cmp(P x, P y) {
    if (x.second != y.second) return x.second > y.second;
    return x.first > y.first;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    int n;
    cin >> n;
    vector<P> all(n);
    for (int i = 0; i < n; ++i) {
        cin >> all[i].first >> all[i].second;
    }
    sort(all.begin(), all.end(), cmp);
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int f = all[i].first;
        int s = all[i].second;
        if (v.empty()) v.push_back(f);
        else {
            auto p = lower_bound(v.begin(), v.end(), s);
            if (p == v.end()) {
                auto q = lower_bound(v.begin(), v.end(), f);
                v.insert(q, f);
            }else {
                v.erase(p);
                auto q = lower_bound(v.begin(), v.end(), f);
                v.insert(q, f);
            }
        }
    }
    cout << v.size() << endl;
    return 0;
}