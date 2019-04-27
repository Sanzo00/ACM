#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e2 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
string s;
int solve(int l, int r) {
	int ans = 0;
	for (int i = l; i <= r; ++i) {
		ans = ans * 10 + s[i] - '0';
	}
	return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> s) {
	    int len = s.size();
	    int day = s[len-1] - '0';
	    int l = 0,  r = 0;
    	l = solve(0, 0);
    	r = solve(1, len-2);
    	if (l < 2 || l > 11 || r < 2 || r > 11) {
    		l = solve(0, 1);
    		r = solve(2, len-2);
    	}
	    r += 12;
	    cout << (r - l) * day << endl;
    }
    return 0;
}
