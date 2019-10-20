#include <bits/stdc++.h>
const int maxn = 5e3 + 5;
using namespace std;
char s[maxn];
bool ok[maxn][maxn];
int k, len;
struct Trie{
    int nex[maxn*maxn/2][2], cnt[maxn*maxn/2], end[maxn*maxn/2], fa[maxn*maxn/2];
    char C[maxn*maxn/2];
    int p, root;
    int newnode() {
        fill(nex[p], nex[p]+2, 0);
        cnt[p] = end[p] = 0;
        return p++;
    }
    void init() {
        p = 0;
        root = newnode();
    }
    void add(int u) {
        int now = root;
        for (int i = u; i < len; ++i) {
            if (nex[now][s[i]-'a'] == 0) {
                nex[now][s[i] - 'a'] = newnode();
                C[p-1] = s[i];
                fa[p-1] = now;
            }
            now = nex[now][s[i] - 'a'];
            if (ok[u][i]) end[now]++;
        }
    }
    void print(int u) {
        if (fa[u]) print(fa[u]);
        cout << C[u];
    }
    void dfs(int u) {
        if (end[u]) {
            k -= end[u];
            if (k <= 0) {
                print(u);
                cout << endl;
                exit(0);
            }
        }
        for (int i = 0; i < 2; ++i) {
            if (nex[u][i] == 0) continue;
            dfs(nex[u][i]);
        }
    }
}trie;
int main() {
    cin >> s >> k;
    len = strlen(s);
    trie.init();
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j <= len-i; ++j) {
            int l = j, r = j+i-1;
            if (r - l <= 3) ok[l][r] = (s[l] == s[r]);
            else ok[l][r] = (s[l] == s[r]) && ok[l+2][r-2];
            // if (ok[l][r]) trie.add(l, r); 这里太sb了,超时...
        }
    }
    for (int i = 0; i < len; ++i) trie.add(i);
    trie.dfs(0); 
    return 0;
}