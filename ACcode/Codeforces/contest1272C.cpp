#include <bits/stdc++.h>
using namespace std;
long long num(long long a) {
	long long ans = a * (a + 1);
	return ans / 2;
}
 
int ok[256];
int main() {
	
	int n, k;
	string s;
	cin >> n >> k >> s;
	for (int i = 0; i < k; ++i) {
		char c;
		cin >> c;
		ok[c] = 1;
	}
	int len = 0;
	long long ans= 0;
	for (int i = 0; i < s.size(); ++i) {
		if (ok[s[i]]) len++;
		else {
			ans += num(len);
			len = 0;
		}
	}
	ans += num(len);
	cout << ans << endl;
		
	return 0;
}
