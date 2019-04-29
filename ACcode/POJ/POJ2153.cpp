#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <time.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string s;
	map<string, int> mp;
	int now = 0;
	getline(cin, s);
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		while (s[0] == ' ') s.erase(0, 1);
		mp[s] = now++;
	}
	vector<int> a(n, 0), b(n);
	int m, d;
	cin >> m;
	while (m--) {
		for (int i = 0; i < n; ++i) {
			cin >> d;
			getline(cin, s);
			while (s[0] == ' ') s.erase(0, 1);
			// cout << "s =" << s << endl;
			a[mp[s]] += d;
		}
		for (int i = 0; i < n; ++i) b[i] = a[i];
		int tmp = b[mp["Li Ming"]];
		sort(b.begin(), b.end());
		int ans = b.end() - upper_bound(b.begin(), b.end(), tmp);				
		cout << ans + 1 << endl;
	}

    return 0;
}