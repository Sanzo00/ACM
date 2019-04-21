#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 1e5 + 7;
const int mod = 1000000007;
int pre[maxn], sum[maxn];
int find (int x) {
	return (x == pre[x]) ? x : pre[x] = find(pre[x]);
}

int main () {
	ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m, t;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) pre[i] = i, sum[i] = 1;
    string s;
	int last_; string last;
	while (m--) {
		cin >> t >> s;
		if (s == last) {
			int fx = find(last_);
			int fy = find(t);
			if (fx == fy) continue;
			if (fx > fy) swap(fx, fy);
			pre[fy] = fx;
			sum[fx] += sum[fy];
		}else last_ = t, last = s;
			
	}
	for (int i = 1; i <= n; ++i) {
		if (i > 1) cout << " ";
		cout << sum[find(i)] - 1;
	}
	cout << '\n';

    return 0;
}