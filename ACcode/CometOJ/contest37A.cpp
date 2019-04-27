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

    vector<LL> num, all;
    LL sum = 4, x, tmp;
    for (int i = 0; i < 4; ++i) {
    	num.push_back(1);
    } 
    while (sum < 1e18) {
    	tmp = sum / 2;
    	num.push_back(tmp);
    	sum += tmp;
    }
   	tmp = 0;
    for (LL it : num) {
    	tmp += it;
    	all.push_back(tmp);
    }
    cin >> x;
    int ans = upper_bound(all.begin(), all.end(), x) - all.begin();
    cout << ans + 1<< endl;

    return 0;
}