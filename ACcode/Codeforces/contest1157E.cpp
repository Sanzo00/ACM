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
vector<int> a(maxn);

string s;
string dfs(int l, int r, int x) {
	if (l == r && a[l] > x) {
		return "L";
	}
	if (l == r && a[l] < x) {
		return "";
	}
	if (a[l] > a[r] && a[r] > x) return dfs(l, r-1, a[r]) + "R";
	if (a[l] > a[r] && a[r] < x && a[l] > x) return dfs(l+1, r, a[l]) + "L";
	if (a[r] > a[l] && a[l] > x) return dfs(l+1, r, a[l]) + "L";
	if (a[r] > a[l] && a[l] < x && a[r] > x) return dfs(l, r-1, a[r]) + "R";
	if (a[l] == a[r] && a[l] < x) return "";
	else {
		string s = dfs(l+1, r, a[l]) + "L";
		string t = dfs(l, r-1, a[r]) + "R";
		if (s.size() > t.size()) {
			return s;
		}else return t;
	}
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}    
	string ans = dfs(0, n-1, 0);
	cout << ans.size() << endl;
	cout << ans << endl;

    return 0;
}