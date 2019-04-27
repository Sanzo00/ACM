#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
char s[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    string s, t;
    cin >> n;
    map<string, int>mp;
    set<string> st;
    getline(cin, s);
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		t = s[0];
		int len = s.size();
		for (int i = 1; i < len; ++i) {
			if (s[i] != ' ' && s[i-1] == ' ') t += s[i];
		}		
		mp[t]++;
		st.insert(t);
	}    
	LL ans = 0;
	for (string it : st) {
		if (mp[it] < 2) continue;
		LL tmp = mp[it];
		ans += tmp * (tmp - 1) / 2;
	}
	printf("%lld\n", ans);
    return 0;
}
