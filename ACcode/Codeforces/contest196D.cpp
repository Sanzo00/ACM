#include <bits/stdc++.h>
#define ull unsigned long long
const int maxn = 4e5 + 5;
using namespace std;
int d, len;
char s[maxn], t[maxn];
ull hash_l[maxn], hash_r[maxn], p[maxn], base = 131;
ull get_l(int x, int y) {
    return hash_l[x] - hash_l[x-y] * p[y+1];
}
ull get_r(int x, int y) {
    return hash_r[x] - hash_r[x-y];
}
int check(int x) {
    if (x >= d && get_l(x, d)*p[x-d+1] == get_r(x, d)) {
        return 1;
    }

    if (x > d && get_l(x, d+1)*p[x-d] == get_r(x, d+1)) return 1; 
    return 0;
}
int dfs(int x, int sta) {
    if (x > len) {
        return 1;
    }
    char c = sta ? s[x] : 'a';
    for (char i = c; i <= 'z'; ++i) {
        t[x] = i;
        hash_l[x] = hash_l[x-1] * base + (i-'a'+1);
        hash_r[x] = hash_r[x-1] + p[x] * (i-'a'+1);
        if (check(x)) continue;
        if (dfs(x+1, sta && t[x] == s[x])) return 1;
    }
    return 0;
}
int main() {
    cin >> d >> s+1;
    len = strlen(s+1);
    for (int i = len; i >= 1; --i) {
        if (s[i] == 'z') s[i] = 'a';
        else {
            s[i]++;
            break;
        }
        if (i == 1) {
            cout << "Impossible\n";
            return 0;
        }
    }
    p[1] = 1;
    for (int i = 2; i <= len; ++i) p[i] = p[i-1] * base;
    if (dfs(1, 1)) cout << t+1 << endl;
    else cout << "Impossible\n";
    return 0;
}
