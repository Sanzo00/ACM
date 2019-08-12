#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 805306457;
using namespace std;
char ans[maxn];
struct Hash{
    long long p[maxn], hash[maxn], hash1[maxn], base = 131;
    int now;
    long long getHash(int l, int r, int t) {
        long long ans;
        if (t == 0) ans = (hash[r] - hash[l-1] * p[r-l+1]) % mod;   
        else ans = (hash1[r] - hash1[l-1] * p[r-l+1]) % mod;
        return (ans + mod) % mod;
    }
    void init() {
        now = 0;
        p[0] = 1;
        for (int i = 1; i < maxn; ++i) p[i] = p[i-1] * base % mod;
    }
    void insert(string s) {
        int len = s.size();
        for (int i = 1; i <= len; ++i) {
            hash1[i] = (hash1[i - 1] * base % mod + (s[i-1] - 'a' + 1)) % mod;
        }
        int mi = min(now, len);
        int l = now - mi + 1;
        int r = now;
        while (l <= r && getHash(l, r, 0) != getHash(1, mi, 1)) l++, mi--;
         for (int i = mi+1; i <= len; ++i) {
            now++;
            hash[now] = (hash[now-1] * base % mod + (s[i-1] - 'a' + 1)) % mod;   
            ans[now] = s[i-1];
        }
    }
}hh;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    hh.init();
    int n;
    string s;
    cin >> n;
    hh.init();
    for (int i = 0; i < n; ++i) {
        cin >> s;
        hh.insert(s);
    }
    for (int i = 1;  i<= hh.now; ++i) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}