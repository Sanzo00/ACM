#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int flag = 0;
    for (int i = 0; i < 16; ++i) {
    	int sum1 = 0, sum2 = 0;
    	for (int j = 0; j < 4; ++j) {
    		if (i&(1<<j)) sum1 += a[j];
    		else sum2 += a[j];
    	}
    	if (sum1 == sum2) flag = 1;
    }
    if (flag == 0) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}
