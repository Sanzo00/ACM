#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 2e5 + 7;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, b, a;
    cin >> n >> b >> a;
    int t = a;
    vector<int> v(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	cin >> v[i];
    	if (a == 0 && b == 0) break;
    	if (v[i] == 0) {
    		if (a) a--;
    		else b--;
    	}else {
    		if (b && a < t) {
    			b--, a++;
    		}else if (b && a == t){
    			a--;
    		}else if (a) a--;
    		else break;
    	}
    	ans++;
    }
    cout << ans << endl;
    return 0;
}