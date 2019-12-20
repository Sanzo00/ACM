#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
 
int main() {
	
	int q;
	cin >> q;
	while (q--) {
		string s, t, ss;
		cin >> s >> t;
		if (s < t) {
			cout << s << endl;
			continue;
		}
		ss = s;
		sort(ss.begin(), ss.end());
		if (ss >= t) {
			cout << "---\n";
			continue;
		}

		int len = s.size();
		for (int i = 0; i < len; ++i) {
			if (s[i] == ss[i]) continue;
			for (int j = i+1; j < len; ++j) {
				swap(s[i], s[j]);
				if (s < t) {
					cout << s << endl;
					goto here;
				}
				swap(s[i], s[j]);
			}
		}
		cout << "---\n";
		here: ;
	}
	return 0;
}