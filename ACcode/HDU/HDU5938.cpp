#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
long long get(string s) {
	long long t = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		t = t * 10 + s[i] - '0';
	}
	return t;
} 
long long solve(vector<string> v) {
	string t = v[0];
	long long tmp = max(get(t.substr(0,1)) + get(t.substr(1, 20)), get(t.substr(0,v[0].size()-1)) + get(t.substr(v[0].size()-1, 1)));
	long long ans = get(v[1]) * get(v[2]) / get(v[3]);
	ans = tmp - ans;
	return ans;
}
int len;
string s;
vector<string> str(int last) {
	vector<string> tmp;
	string t; 
	for (int i = 0; i <= len-4-last+1; ++i) t += s[i]; 
	tmp.push_back(t);
	t = s[len-3-last+1], tmp.push_back(t);
	t = s[len-2-last+1], tmp.push_back(t);
	t.clear();
	for (int i = len-1-last+1; i < len; ++i) t += s[i];
	tmp.push_back(t);
	return tmp;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T, kase = 1;
	cin >> T;
	while (T--) {
		cout << "Case #" << kase++ << ": ";
		cin >> s;
		len = s.size();
		long long ans = solve(str(1));
		if (len > 5) ans = max(ans, solve(str(2)));
		cout << ans << endl;
	}
	return 0;
}