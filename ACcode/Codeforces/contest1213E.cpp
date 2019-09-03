#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	while (cin >> n) {
		vector<string> str;
		string a, b, c = "abc";
		cin >> a >> b;
		do {
			string t;
			for (int i = 0; i < n; ++i) t += c;
			str.push_back(t);
			str.push_back(string(n, c[0]) + string(n, c[1]) + string(n, c[2])); 
		}while (next_permutation(c.begin(), c.end()));
		for (int i = 0; i < 12; ++i) {
			if (str[i].find(a) == string::npos && str[i].find(b) == string::npos) {
				cout << "YES\n";
				cout << str[i] << endl;
				break;
			}
		}
	}
	return 0;
}