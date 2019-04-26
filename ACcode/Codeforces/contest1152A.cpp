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

    int n, m, d;
    cin >> n >> m;
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
    	cin >> d;
    	if (d & 1) odd++;
    	else even++;
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
    	cin >> d;
    	if (d & 1 && even) {
    		ans++;
    		even--;
    	}else if ((d+1) & 1 && odd) {
    		ans++;
    		odd--;
    	}
    }
    cout << ans << endl;
    return 0;
}