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

    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        vector<int> b(a.begin(), a.begin() + i);
        sort(b.begin(), b.end());
        long long sum = 0;
        for (int j = i-1; j >= 0; j -= 2) {
            sum += b[j];
        }
        if (sum <= h) {
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}