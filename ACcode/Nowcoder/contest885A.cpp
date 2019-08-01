#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int n;
int check(string s) {
    int len = s.size();
    long long sum = 0;
    for (int i = 0; i < len; ++i) sum += s[i] - '0';
    if (sum % n == 0) return 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s;
        int len = s.size();
        n = 0;
        for (int i = 0; i < len; ++i) n = n * 10 + s[i] - '0';
        t = s;
        while (1) {
            if (check(t)) break;
            t += s;
        }
        cout << t << endl;
    }
    return 0;
}