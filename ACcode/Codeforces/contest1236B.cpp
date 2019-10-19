#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
using namespace std;
long long Pow(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}
int main() {
    long long n, m, ans;
    cin >> n >> m;
    ans = Pow(2, m) - 1;
    ans = (ans + mod) % mod;
    ans = Pow(ans, n);
    cout << ans << endl;
    return 0;
}