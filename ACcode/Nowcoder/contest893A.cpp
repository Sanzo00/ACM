#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 3e2 + 1;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, p, s, n1, p1, s1;
    cin >> n >> p >> s >> n1 >> p1 >> s1;
    if (n < n1) {
    	cout << 2 << endl;
    }else if (n > n1) {
    	cout << 1 << endl;
    }else {
    	if (p < p1) {
    		cout << 1 << endl;
    	}else if (p > p1) {
    		cout << 2 << endl;
    	}else {
    		if (s < s1) {
    			cout << 1 << endl;
    		}else if (s > s1) {
    			cout << 2 << endl;
    		}else {
    			cout << "God" << endl;
    		}
    	}
    }

    return 0;
}
