#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 5e5 + 5;
using namespace std;

int main () {

    int n;
    cin >> n;
    vector<int> f_p(n), f_h(n), b_p(n), b_h(n); 
    for (int i = 0; i < n; ++i) {
        cin >> b_p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b_h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> f_p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> f_h[i];
    }
    vector<int> b_order(n), f_order(n);
    iota(b_order.begin(), b_order.end(), 0);
    iota(f_order.begin(), f_order.end(), 0);
    sort(f_order.begin(), f_order.end(), [&] (int x, int y) {return f_p[x] < f_p[y];});
    sort(b_order.begin(), b_order.end(), [&] (int x, int y) {return b_p[x] < b_p[y];});
    int b_i = 0, f_i = 0;
    set<pair<int, int>> b_s, f_s;
    vector<int> b_ans(n), f_ans(n);

    for (int i = 0; i < n; ++i) {
        if (b_s.empty()) {
            while (b_i < n) {
                b_s.emplace(b_h[b_order[b_i]], b_order[b_i]);
                b_i++;
                if (b_i == n || b_p[b_order[b_i]] != b_p[b_order[b_i - 1]]) break;
            }
        }
        if (f_s.empty()) {
            while (f_i < n) {
                f_s.emplace(f_h[f_order[f_i]], f_order[f_i]);
                f_i++;
                if (f_i == n || f_p[f_order[f_i]] != f_p[f_order[f_i - 1]]) break;
            }
        }
        if (b_s.size() < f_s.size()) {
            int t = b_s.begin()->second;
            b_s.erase(b_s.begin());
            b_ans[i] = t;
            auto it = f_s.lower_bound(make_pair(b_h[t], 0));
            if (it == f_s.begin()) {
                cout << "impossible\n";
                return 0;
            }
            it = prev(it);
            f_ans[i] = it->second;
            f_s.erase(it);
        }else {
            int t = f_s.begin()->second;
            f_s.erase(f_s.begin());
            f_ans[i] = t;
            auto it = b_s.upper_bound(make_pair(f_h[t], n));
            // auto it = b_s.lower_bound(make_pair(f_h[t] + 1, 0));
            if (it == b_s.end()) {
                cout << "impossible\n";
                return 0;
            }
            b_ans[i] = it->second;
            b_s.erase(it);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << b_ans[i]  + 1; 
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << f_ans[i] + 1; 
    }
    cout << '\n';

    return 0;
}
