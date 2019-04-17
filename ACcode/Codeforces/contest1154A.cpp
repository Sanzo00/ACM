#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 2e5 + 7;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<int> a(4);
    for (int i = 0; i < 4; ++i) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    int t = a[3];
    for (int i = 0; i < 3; ++i) {
    	cout << t - a[i] << " ";
    }
    cout << endl;
    return 0;
}