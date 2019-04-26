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
int judge(char x, char y) {
	if (x >= 'a' && y >= 'a') return 0;
	if (x <= 'Z' && y <= 'Z') return 0;
 	if (x >= 'a' && x - 'a' != y - 'A') return 0;
    if (x <= 'Z' && x - 'A' != y - 'a') return 0;
    return 1;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    int len = s.size();
    int ans = 0;
    for (int i = 0; i < len; ++i) {
    	for (int j = i + 1; j < len; ++j) {
    		if ((j - i) % 2 == 0 || judge(s[i], s[j]) == 0 || j-i+1 <= ans) continue;
    		int l = i, r = j;
    		while (l < r) {
    			if (judge(s[l], s[r])) {
    				l++;
    				r--;
    			}else break;
    		}
    		if (l > r) ans = max(ans, j - i + 1);
    	}
    }
    cout  << ans << endl;
    return 0;
}