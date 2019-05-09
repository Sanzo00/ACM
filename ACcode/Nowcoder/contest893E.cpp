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
    int T;
    cin >> T;
    while (T--) {
    	int n, m;
    	cin >> n >> m;
    	vector<int> a(n);
    	int pos, Max = -1;
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    		if (a[i] > Max) {
    			Max = a[i];
    			pos = i;
    		}
    	}

    	int i = 0;
    	int l = m, r = m;
    	while (true) {
    		i %= n;
    		if (i == pos) {
    			if (l == 0) {
    				cout << "YES\n";
    				break;
    			}
    			r = max(0, r - a[i]);
    			l = max(0, l - a[i]);
    			
    		}else {
    			if (r == 0) {
    				cout << "NO\n";
    				break;
    			}
    			r = max(0, r - 1);
    			l = max(0, l - a[i]);
    		}
    		++i;
    	}
    }
    return 0;
}