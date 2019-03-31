#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 1001;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int mod = 1e9 + 7;
struct ac{
    int d, x;
    bool operator < (const ac &t) {
        return x > t.x;
    }
}a[maxn], b[maxn];

void solve(string s, int &d, int &x) {
    int flag = 1;
    int len = s.size();
    if (s[0] == '-') flag = -1;
    int now = 0;
    if (s[0] == '+' || s[0] == '-') now = 1;
    int xx;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '^') {
            xx = i + 1;
            break;
        }
    }
    int num = 0;
    for (int i = now; s[i] != 'x'; ++i) {
        num = num * 10 + s[i] - '0';
    }
    d = num * flag;
    num = 0;
    for (int i = xx; i < len; ++i) {
        num = num * 10 + s[i] - '0';
    }
    x = num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    string s, t, tmp;
    cin >> s >> t;
    int lens, lent;
    int ls = s.size();
    int lt = t.size();
    int now = 1;
    map<int,int> mp;
    //处理第一个多项式
    for (int i = 0; i < ls; ++i) {
        if (i == ls-1 || (i && (s[i] == '+' || s[i] == '-'))) {
            if (i == ls-1) tmp += s[i];
            int d, x;
            solve(tmp, d, x);
            if (mp[x]) {//去重
                a[mp[x]].d += d;
                tmp = s[i];
                continue;
            }
            mp[x] = now;
            a[now].d = d;
            a[now++].x = x;
            tmp = s[i];
        }else tmp += s[i];
    }
    mp.clear();
    lens = now;
    now = 1;
    tmp = "";
    // 处理第二个多项式
    for (int i = 0; i < lt; ++i) {
        if (i == lt-1 || (i && (t[i] == '+' || t[i] == '-'))) {
            if (i == lt-1) tmp += t[i];
            int d, x;
            solve(tmp, d, x);
            if (mp[x]) {
                b[mp[x]].d += d;
                tmp = t[i];
                continue;
            }
            mp[x]=now;
            b[now].d = d;
            b[now++].x = x;
            tmp = t[i];
        }else tmp += t[i];
    }
    lent = now;
    sort(a+1, a + lens+1);
    sort(b+1, b + lent+1);
    int n, m = -1, a0, b0;
    for (int i = 1; i < lens; ++i) {
        if (a[i].d != 0) {
            a0 = a[i].d;            
            m = a[i].x;
            break;
        }
    }
    for (int i = 1; i < lent; ++i) {
        if (b[i].d != 0) {
            b0 = b[i].d;            
            n = b[i].x;
            break;
        }
    }    
    
    if (n > m) cout << 0 << endl;
    else if (n < m) cout << "oo\n";
    else {
        int tt = __gcd(abs(a0), abs(b0));
        a0 /= tt;
        b0 /= tt;
        if (b0 < 0) {
            b0 *= -1;
            a0 *= -1;
        }
        if (b0 == 1) cout << a0 << endl;
        else cout << a0 << "/" << b0 << endl;
    }
    
    return 0;
}