#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 1000001;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
LL mod = 1e9 + 7;
LL jie[maxn];
LL exgcd(LL a, LL b, LL &x, LL &y) {
    LL d = a;
    if (b == 0) x = 1,y = 0;
    else {
        d = exgcd(b, a%b, y, x);
        y -= a / b * x;
    }
    return d;
}

LL inv(LL a, LL mod) {
    LL x, y;
    LL d = exgcd(a, mod, x, y);
    return (d == 1) ? ((x + mod) % mod) : -1; 
}

LL pow(LL x, LL a) {
    LL ans = 1;
    while (a) {
        if (a&1) ans = ans * x % mod;
        x = x * x % mod;
        a >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    int n, m;
    jie[1] = jie[0] = 1;
    for (LL i = 2; i < maxn; ++i) {
        jie[i] = jie[i-1] * i % mod;
    }
    while (cin >> n >> m) {
        vector<LL> su;
        for (LL i = 2; i * i <= m; ++i) {
            if (m % i == 0) {
                su.push_back(i);
                while (m % i == 0) m /= i;
            }
        }
        if (m > 1) su.push_back(m);

        LL ans = jie[n];
        int len = su.size();
        for (int i = 1; i < (1<<len); ++i) {
            int cnt = 0;
            LL t = 1; 
            for (int j = 0; (1<<j) <= i; ++j) {
                if (i & (1<<j)) {
                    cnt++;
                    t = t * su[j] % mod;
                }
            }
            LL x = jie[n/t] * pow(t, n/t) % mod;
            if (cnt & 1) ans = ans * inv(x, mod) % mod;
            else ans = ans * x % mod;
        }
        cout << ans << endl;        
    }
    
    return 0;
}