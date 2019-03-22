#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 100005;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   

    int n;
    cin >> n;
    vector<string> all(n);
    for (int i = 0; i < n; ++i) {
        cin >> all[i];
    }
    reverse(all.begin(), all.end());
    int flag = 1;
    for (auto it : all) {
        if (it == "LIE") flag ^= 1;
    }
    if (flag) cout << "TRUTH\n";
    else cout << "LIE\n";

    return 0;
}