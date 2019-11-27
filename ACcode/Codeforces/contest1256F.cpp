#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int a[300], b[300], c[maxn];
int posa[300], posb[300];
int N;
int add(int x) {
    while (x < N) {
        c[x]++;
        x += x & (-x);
    }
}
int get(int x) {
    int cnt = 0;
    while (x) {
        cnt += c[x];
        x -= x & (-x);
    }
    return cnt;
}
int main() {
    int q, n;
    cin >> q;
    string s, t;
    while (q--) {
        fill(a, a+300, 0);
        fill(b, b+300, 0);
        cin >> n >> s >> t;
        N = n + 5;
        int f1 = 1, f2 = 0;
        for (int i = 0; i < n; ++i) {
            a[s[i]]++;
            posa[s[i]] = i+1;
        }
        for (int i = 0; i < n; ++i) {
            b[t[i]]++;
            posb[t[i]] = i+1;
        }
        for (int i = 0; i < 300; ++i) {
            if (a[i] != b[i]) f1 = 0;
            if (a[i] > 1) f2 = 1;
        }
        if (f1 == 0) cout << "NO" << endl;
        else if (f2) cout << "YES" << endl;
        else {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                int pos;
                for (int j = i; j < n; ++j) {
                    if (s[i] == t[j]) {
                        pos = j;
                        break;
                    }
                }
                if (pos == i) continue;
                cnt += pos - i;
                char c = t[pos];
                t.erase(pos, 1);
                t.insert(i, 1, c);
            } 
            if (cnt & 1) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}
