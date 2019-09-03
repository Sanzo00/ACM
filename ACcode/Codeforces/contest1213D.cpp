#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
vector<vector<int>> all(maxn);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k, d;
    scanf("%d %d", &n, &k);
    long long ans = 1e18;
    for (int i = 0; i < n; ++i) {
    	scanf("%d", &d);
    	int cnt = 0;
    	while (d) {
    		all[d].push_back(cnt);
    		cnt++;
    		d /= 2;
    	}
    }
    for (int i = 0; i < maxn; ++i) {
    	sort(all[i].begin(), all[i].end());
    	if ((int)all[i].size() < k) continue;
    	ans = min(ans, accumulate(all[i].begin(), all[i].begin()+k, 0ll));
    }
    printf("%lld\n", ans);
    return 0;
}
