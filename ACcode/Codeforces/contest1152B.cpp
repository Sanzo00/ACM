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
    vector<int> ans;
    int cnt = 0;
    LL x;
    cin >> x;
    set<LL> st;
    for (LL i = 1; i <= 60; ++i) {
    	st.insert((1ll << i) - 1);
    }
    while (1) {

    	if (st.find(x) != st.end()) {
    		break;
    	}
    	// A
    	LL t = log2(x);
    	while ((1ll << t) & x) t--;
    	t++;
    	ans.push_back(t);
    	x ^= (1ll << t) - 1;
    	cnt++;

    	if (st.find(x) != st.end()) {
    		break;
    	}
    	// B
    	cnt++;
    	x += 1;
    	if (st.find(x) != st.end()) {
    		break;
    	}
    }

    cout << cnt << endl;
    for (int it : ans) {
    	cout << it << " ";
    }
    return 0;
}