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
    vector<int> a(n), ans;
    multiset<int> st;

    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    for (int i = 0, d; i < n; ++i) {
    	cin >> d;
    	st.insert(d);
    }
 	for (int i = 0; i < n; ++i) {
 		auto it = st.find(n - a[i]);
 		if (it != st.end()) {
 			ans.push_back(0);
 			st.erase(it);
 		}else {
 			auto q = st.lower_bound(n-a[i]);
 			if (q == st.end()) {
 				q = st.begin();
 			}
			ans.push_back(((*q + a[i]) % n));
			st.erase(q);
 		}
 	}
 	for (int i = 0; i < n; ++i) {
 		if (i > 0) cout << " ";
 		cout << ans[i];
 	}
 	cout << endl;
    return 0;
}