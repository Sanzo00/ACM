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

    int n, k;
    cin >> n >> k;
    vector<int> a(n), l(n), r(n);
    for (int i = 0; i < n; ++i) {
    	l[i] = i;
    	r[i] = i;
    }
    map<int,int> mp, vis, ans;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	mp[a[i]] = i;
    }
    int now = 2;
    vector<int> tmp;
    for (int i = n; i >= 1; --i) {
    	if (vis[i]) continue;
    	vis[i] = 1;
    	ans[i] = now % 2;
    	int pos = mp[i];
    	int t = k;
    	int j;
    	tmp.clear();
    	tmp.push_back(pos);
    	for (j = pos; j < n && t; ) {
    		if (r[j] != j) j = r[j];
    		else j++;
    		if (j >= n) break;
    		if (vis[a[j]]) continue;
    		tmp.push_back(j);
    		vis[a[j]] = 1;
    		ans[a[j]] = now % 2;
    		t--;
    		
    	}
    	for (int it : tmp) {
    		r[it] = j;
    	}
    	tmp.clear();
    	tmp.push_back(pos);
    	t = k;
    	for (j = pos; j >= 0 && t; ) {
    		if (l[j] != j) j = l[j];
    		else j--;
    		if (j < 0) break;
    		if (vis[a[j]]) continue;
    		vis[a[j]] = 1;
    		tmp.push_back(j);
    		ans[a[j]] = now % 2;
    		t--;	
    	}
    	for (int it : tmp) {
    		l[it] = j;
    	}
    	now++;
    }
    for (int i = 0; i < n; ++i) {
    	cout << ans[a[i]]+1;
    }
    cout << endl;
    return 0;
}