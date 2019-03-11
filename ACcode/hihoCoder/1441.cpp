#include <bits/stdc++.h>
#define LL  long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define maxn 1000030
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    string s;
    cin >> s >> n;
    m = s.size();
    map<LL, string> longer, smaller;
    map<string, LL> status;
    for (int i = 0; i < m; ++i) {
    	for (int j = 1; j <= m-i; ++j) {
    		string x = s.substr(i, j);
    		LL st = 0;
    		for (int k = 0; k <= m-j; ++k) {
    			string y = s.substr(k, j);
    			if (x == y) {
    				st |= 1LL << (k+j);
    			}
    		}
    		status[x] = st;
    		if ((int)longer[st].size() < j) longer[st] = x;
    		if (!(int)smaller[st].size() || j < (int)smaller[st].size()) smaller[st] = x;
    	}
    }
    while (n--) {
    	cin >> s;
    	LL tmp = status[s];
    	cout << smaller[tmp] << " " << longer[tmp];
    	for (int i = 1; ; ++i) {
    		if ((1LL << i) > tmp) break;
    		if (tmp & (1LL << i)) cout << " " << i;
    	}
    	cout << endl;
    }
    return 0;
}
