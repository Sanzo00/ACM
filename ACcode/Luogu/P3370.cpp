#include <bits/stdc++.h>
#define LL long long
#define uLL unsigned long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 5e5 + 5;
const int mod = 19260817;
const int mod1 = 19260877;
const int seed = 131;

set<P> st;
int Hash(string s, int mod) {
    int len = s.size();
    LL sum = 0;
    for (int i = 0; i < len; ++i) {
        sum = (sum * seed + s[i]) % mod;
    }
    return sum;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        int l = Hash(s, mod);
        int r = Hash(s, mod1);
        st.insert(make_pair(l, r));
    }
    cout << st.size() << endl;

}

