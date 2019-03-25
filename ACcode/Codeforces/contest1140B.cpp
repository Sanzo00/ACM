#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 10005;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int left = 0, right = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '>') left++;
            else break;
        }
        for (int i = n-1; i >= 0; --i) {
            if (s[i] != '<') right++;
            else break;
        }
        cout << min(left, right) << endl;
    }

    return 0;
}