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
int check(int x) {
	int sum = 0;
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	return !(sum % 4);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	while (1) {
		if (check(n)) break;
		n++;
	}		
	cout << n << endl;
	return 0;
}