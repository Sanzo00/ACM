#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 130;
LL a[130][120];
int main() {
    int n;
    cin >> n;
    if (n == 0) {
    	cout << "1/1\n";
    	return 0;
    }
    a[1][1] = a[1][2] = a[1][3] = a[1][4] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= i*4; ++j) {
            LL t = 0;
            for (int k = max(1, j-4); k < j; ++k) {
                t += a[i-1][k];
            }
            a[i][j] = t;
        }
    }
    LL sum = 1, cnt = 0;
    for (int i = n; i <= 4*n; ++i) {
        if (i >= n*3) cnt += a[n][i];
    }
    for (int i = 1; i <= n; ++i) {
        sum *= 4;
    }
    LL tmp = __gcd(sum, cnt);
    sum /= tmp;
    cnt /= tmp;
    cout << cnt << "/" << sum << endl;
    return 0;
}