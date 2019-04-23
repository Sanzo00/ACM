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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int cnt = 0;
    string s;
    cin >> s;
    int flag = n - 11;
    for (int i = 0; i <= flag; ++i) {
    	if (s[i] == '8') cnt++;
    }
    if (cnt >= flag / 2 + 1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}