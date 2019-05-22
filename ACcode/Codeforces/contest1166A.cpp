#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;

int main() {
    
    string s;
    int n;
    map<char,int> mp;
    set<char> st;
    cin >> n;
    while (n--) {
        cin >> s;
        mp[s[0]]++;
        st.insert(s[0]);
    }
    LL ans = 0;
    for (auto it : st) {
        LL tmp = mp[it];
        LL t1 = tmp / 2;
        LL t2 = tmp - t1;
        ans += (t1 - 1) * t1 / 2;
        ans += (t2 - 1) * t2 / 2;
    }
    cout << ans << endl;
    
    return 0;
}