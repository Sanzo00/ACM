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

int num[maxn];
void Add(int x, int d) {
    x++;
    while (x < maxn) {
        num[x] += d;
        x += lowbit(x);
    }
}
int Sum(int x) {
    x++;
    int sum = 0;
    while(x > 0) {
        sum += num[x];
        x -= lowbit(x);
    }
    return sum;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    LL m;
    while (cin >> n >> m) {
        mem(num, 0);
        vector<LL> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i) a[i] += a[i-1];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        for (LL it : a) {
            Add(lower_bound(b.begin(), b.end(), it) - b.begin(), 1);
        }
        LL ans = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            if (i) sum = a[i-1];
            LL tmp = Sum(lower_bound(b.begin(), b.end(), sum+m) - b.begin()-1);
            ans += tmp;
            Add(lower_bound(b.begin(), b.end(), a[i]) - b.begin(), -1);
        }
        cout << ans << endl;
    }
    return 0;
}