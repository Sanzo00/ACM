#include <bits/stdc++.h>
const int maxn = 5e5 + 5;
using namespace std;
struct Trie{
    int nex[maxn][26], fail[maxn], end[maxn];
    int root, p;
    inline int newnode() {
        for (int i = 0; i < 26; ++i) nex[p][i] = -1;
        end[p++] = 0;
        return p - 1;
    }
    inline void init() {
        p = 0;
        root = newnode();
    }
    inline void insert(char *buf) {
        int now = root;
        for (int i = 0; buf[i]; ++i) {
            if (nex[now][buf[i]-'a'] == -1) nex[now][buf[i]-'a'] = newnode();
            now = nex[now][buf[i]-'a'];
        }
        end[now]++;
    } 
    inline void build() {
        queue<int> que;
        fail[root] = root;
        for (int i = 0; i < 26; ++i) {
            if (nex[root][i] == -1) nex[root][i] = root;
            else {
                fail[nex[root][i]] = root;
                que.push(nex[root][i]);
            }
        }
        while (!que.empty()) {
            int now = que.front();
            que.pop();
	    // g[fail[now]].push_back(now); fail树
            for (int i = 0; i < 26; ++i) {
                if (nex[now][i] == -1) nex[now][i] = nex[fail[now]][i];
                else {
                    fail[nex[now][i]] = nex[fail[now]][i];
                    que.push(nex[now][i]);
                }
            }
        }
    }
}ac;
char s[maxn];
int l[maxn], r[maxn];
int main() {
    int now = 0;
    int n, m;
    sam.init();
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        l[i] = now;
        scanf("%s", s+now);
        sam.build(s+now);
        now = strlen(s);
        r[i] = now;
    }
    for (int i = 1; i <= n; ++i) {
        sam.init(s, l[i], r[i], i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%s", s);
        printf("%d\n", sam.solve(s));
    }
    return 0;
}
