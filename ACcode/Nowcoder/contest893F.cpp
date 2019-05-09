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
int n, m;
int solve(string s, int len) {
	int i = 0, j = 0, cnt = 0;
	int ans = 0;
	while (j < len) {
		if (s[j] == '0') cnt++;
		while (cnt > m) {
			if (s[i] == '0') cnt--;
			i++;
		}
		ans = max(ans, j - i + 1);
		j++;
	}
	return ans;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
    	string s;
    	cin >> n >> m >> s;
    	int len = s.size();
    	int ans = solve(s, len);
    	for (int i = 0; i < len; ++i) {
    		if (s[i] == '0') s[i]++;
    		else s[i]--;
    	}
    	ans = max(ans, solve(s, len));
    	cout << ans << endl;
    }
    return 0;
}