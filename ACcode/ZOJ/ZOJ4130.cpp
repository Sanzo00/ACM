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
string s;
int n, k;
void find(int &l, int &r) {
	l = -1;
	r = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			l = i;
			break;
		}
	}
	for (int i = n-1; i >= 0; --i) {
		if (s[i] == '1') {
			r = i;
			break;
		}
	}
}
int check(int x, int l, int r) {
	int pos = l;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < x; ++j) pos++;
		if (pos > r) return 1;
		while (s[pos] != '1' && pos < r) ++pos;
		if (s[pos] != '1') return 1;
	}
	for (int i = pos; i <= r; ++i) {
		if (s[i] == '1') return 0;
	}
	return 1;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T, l, r;
    cin >> T;
    while (T--) {
    	cin >> n >> k >> s;
    	int ans = 0;
    	find(l, r);
    	if (l == -1) {
    		cout << 0 << endl;
    		continue;
    	}
    	int tl = l, tr = r;
    	r = tr - tl + 1;
    	l = 1;
    	while (l <= r) {
    		if (check(mid, tl, tr)) r = mid - 1;
    		else l = mid + 1;
    	}
    	ans = l;
    	cout << ans << endl;
    }
    return 0;
}	