#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a == b) {
		cout << a*10 << " " << b*10+1 << endl;
	}else if (a+1 == b) {
		cout << a*10+9 << " " << b*10 << endl;
	}else if(a + 1 == b*10){
		cout << a << " " << b*10 << endl;
	}else cout << -1 << endl;
	return 0;
}
