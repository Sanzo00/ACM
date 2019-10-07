#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct BIT{
    int C[maxn];
    int lowbit(int x) {return x & -x;}
    void add(int x, int d) {
        while (x < maxn) {
            C[x] += d;
            x += lowbit(x);
        }
    }
    int query(int x) {
        int sum = 0;
        while (x) {
            sum += C[x];
            x -= lowbit(x);
        }
        return sum;
    }
    int query(int l, int r) {
        return query(r) - query(l-1);
    }
}T[26];
int main() {
    string s;
    cin >> s;
    for (int i = 0; i  < (int)s.size(); ++i) T[s[i] - 'a'].add(i+1, 1);
    int n;
    cin >> n;
    while (n--) {
        int l, r, q;
        char c;
        cin >> q;
        if (q == 1) {
            cin >> l >> c;
            T[s[l-1] - 'a'].add(l, -1);
            T[c - 'a'].add(l, 1);
            s[l-1] = c;
        }else {
            cin >> l >> r;
            int ans = 0;
            for (int i = 0; i < 26; ++i) {
                if (T[i].query(l, r)) ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
