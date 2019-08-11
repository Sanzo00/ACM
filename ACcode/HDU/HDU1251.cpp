#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
using namespace std;
struct Trie{
    int nex[maxn][26], cnt[maxn], end[maxn];
    int p, root; // root = 0
    int newnode() {
        memset(nex[p], 0, sizeof(nex[p]));
        cnt[p] = end[p] = 0;
        return p++;
    }
    void init() {
        p = 0;
        root = newnode();
    }
    void add(char *s) {
        int now = root;
        for (int i = 0; s[i]; ++i) {
            if (nex[now][s[i] - 'a'] == 0) nex[now][s[i] - 'a'] = newnode();
            now = nex[now][s[i] - 'a'];
            cnt[now]++;
        }
        end[now] = 1;
    }
    int find(char *s) {
        int now = root;
        for (int i = 0; s[i]; ++i) {
            if (nex[now][s[i] - 'a'] == 0) return 0;
            now = nex[now][s[i] - 'a'];
        }
        return cnt[now];
    }
}trie;
char s[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    trie.init();
    while (fgets(s, maxn, stdin)) {
        if (s[0] == '\n') break;
        int len = strlen(s);
        s[len-1] = 0;
        trie.add(s);
    }
    while (scanf("%s", s) != EOF) {
        printf("%d\n", trie.find(s));
    }
    return 0;
}