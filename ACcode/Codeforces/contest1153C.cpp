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

    string s;
    int n;
    cin >> n >> s;
    if (n & 1) {
    	cout << ":(" << endl;
    	return 0;
    }
    int l = 0;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == '(') l++;
    }
    if (l > n/2) {
    	cout << ":(" << endl;
    	return 0;
    }
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == '(') tmp++;
    	if (s[i] == ')') tmp--;
    	if (s[i] == '?') {
    		if (l < n/2) {
    			tmp++;
    			l++;
    			s[i] = '(';
    		}else {
    			tmp--;
    			s[i] = ')';
    		}
    	}
    	if (tmp < 0 || (tmp == 0 && i < n-1)) {
    		cout << ":(" << endl;
    		return 0;
    	}
    }
    cout << s << endl;


    return 0;
}