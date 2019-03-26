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

    int T;
    string s;
    cin >> T;
    map<char, string> mp;
    mp['a'] = "as";       mp['i'] = "ios";
    mp['y'] = "ios";    mp['l'] = "les";
    mp['n'] = "anes";  
    mp['o'] = "os";     mp['r'] = "res";
    mp['t'] = "tas";       mp['u'] = "us";
    mp['v'] = "ves";       mp['w'] = "was";
    while (T--) {
        cin >> s;
        int len = s.size();
        char l = s[len-2];
        char r = s[len-1];
        if (!mp[r].empty()) {
            s.erase(len-1);
            s += mp[r];
        }else if (l == 'n' && r == 'e'){
            s.erase(len-2);
            // cout << s << endl;
            s += mp['n'];
        }else {
            s += "us";
        }
        cout << s << endl;

    }        

    return 0;
}