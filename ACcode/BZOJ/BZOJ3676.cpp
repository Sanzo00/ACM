#include <bits/stdc++.h>
const int maxn = 3e5 + 4;

using namespace std;
struct Palindromic_Tree{
    int nex[maxn][26];
    int fail[maxn], cnt[maxn], num[maxn];
    int len[maxn], S[maxn];
    int last, n, p;
    int newnode(int l) {
        for (int i = 0; i < 26; ++i) nex[p][i] = 0;
        cnt[p] = num[p] = 0;
        len[p] = l;
        return p++;
    }
    void init() {
        p = 0;
        newnode(0), newnode(-1);
        last = n = 0;
        S[n] = -1;
        fail[0] = 1;
    }
    int get_fail(int x) {
        while (S[n - len[x] - 1] != S[n]) x = fail[x];
        return x;
    }
    void add(int c) {
        c -= 'a';
        S[++n] = c;
        int cur = get_fail(last);
        if (!nex[cur][c]) {
            int now = newnode(len[cur] + 2);
            fail[now] = nex[get_fail(fail[cur])][c];
            nex[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = nex[cur][c];
        cnt[last]++;
    }
    void count() {
        for (int i = p - 1; i >= 0; --i) cnt[fail[i]] += cnt[i];
    }
}Tree;
int ans[1011][1011];
char s[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    scanf("%s", s);
    Tree.init();
    for (int i = 0; s[i]; ++i) {
        Tree.add(s[i]);
    }
    Tree.count();
    long long ans= -1;
    for (int i = 0; i < Tree.p; ++i) {
        ans = max(ans, 1ll * Tree.cnt[i] * Tree.len[i]);
    }
    cout << ans << endl;    
    return 0;
}