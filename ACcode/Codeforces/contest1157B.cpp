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
    string s;
    map<int, int> mp;
    cin >> s;
    for (int i = 1; i <= 9; ++i) {
    	int d;
    	cin >> d;
    	mp[i] = d;
    }
    for (int i = 0; i < n; ++i) {
    	int now = s[i] - '0';
    	if (mp[now] <= now) continue;
    	for (int j = i; j < n; ++j) {
    		if (mp[s[j]-'0'] < s[j]-'0') break;
    		s[j] = mp[s[j]-'0'] + '0';
    	}
    	break;
    }
    cout << s << endl;
    return 0;
}