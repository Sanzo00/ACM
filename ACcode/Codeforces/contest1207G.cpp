#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
char s[maxn];
int ans[maxn];
vector<pair<int,int> > Q[maxn];
struct Bit{
    int c[maxn];
    void init() {fill(c, c+maxn, 0);}
    int lowbit(int x) {return x & (-x);}
    void add(int x, int d) {
        while (x < maxn) {
            c[x] += d;
            x += lowbit(x);
        }
    }
    int getsum(int x) {
        int sum = 0;
        while (x) {
            sum += c[x];
            x -= lowbit(x);
        }
        return sum;
    }
    int query(int l, int r) {
        return getsum(r) - getsum(l-1);
    }
}bit;
struct Trie{
    int nex[maxn][26], idx[maxn];
    int root, p;
    int newnode() {
        fill(nex[p], nex[p]+26, 0);
        return p++;
    }
    void init() {
        p = 0;
        root = newnode();
    }
    void add(int id, int u, int c) {
        u = idx[u];
        if (nex[u][c-'a'] == 0) nex[u][c-'a'] = newnode();
        idx[id] = nex[u][c-'a'];
    }
}trie;
struct AC{
    int nex[maxn][26], fail[maxn];
    int root, p;
    vector<int> g[maxn];
    int in[maxn], out[maxn], cnt;
    int newnode() {
        for (int i = 0; i < 26; ++i) nex[p][i] = -1;
        return p++;
    }
    void init() {
        p = 0;
        cnt = 0;
        root = newnode();
    }
    int insert(char *buf) {
        int now = root;
        for (int i = 0; buf[i]; ++i) {
            if (nex[now][buf[i]-'a'] == -1) {
                nex[now][buf[i]-'a'] = newnode();
            }
            now = nex[now][buf[i]-'a'];
        }
        return now;
    }
    void build() {
        queue<int> que;
        fail[root] = root;
        for (int i = 0; i < 26; ++i) {
            if (nex[root][i] == -1) nex[root][i] = root;
            else {
                fail[nex[root][i]] == root;
                que.push(nex[root][i]);
            }
        }
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            g[fail[now]].push_back(now); // 求fail树
            for (int i = 0; i < 26; ++i) {
                if (nex[now][i] == -1) nex[now][i] = nex[fail[now]][i];
                else {
                    fail[nex[now][i]] = nex[fail[now]][i];
                    que.push(nex[now][i]);
                }
            }
        }
    }
    void dfs(int u) { // 求dfs序
        in[u] = ++cnt;
        for (int i = 0; i < (int)g[u].size(); ++i) {
            int v = g[u][i];
            dfs(v);
        }
        out[u] = cnt;
    }
    void dfs(int u1, int u2) {
        bit.add(in[u2], 1); // 对应AC节点++
        for (int j = 0; j < (int)Q[u1].size(); ++j) { // Trie节点对应有询问
            int pos = Q[u1][j].first;
            int id = Q[u1][j].second;
            ans[id] = bit.query(in[pos], out[pos]);
        }
        for (int i = 0; i < 26; ++i) {
            if (trie.nex[u1][i] == 0) continue;
            dfs(trie.nex[u1][i], nex[u2][i]);
        }
        bit.add(in[u2], -1); // 去掉之前标记
    }
    void solve() {
        build();
        dfs(0); // dfs序
        dfs(0, 0);
    }
}ac; 
int main() {
    scanf("%d", &n);
    trie.init();
    bit.init();
    ac.init();
    for (int i = 1; i <= n; ++i) {
        int op, num;
        char c;
        scanf("%d", &op);
        if (op == 2) {
            scanf("%d %c", &num, &c);
            trie.add(i, num, c);
        }else {
            scanf(" %c", &c);
            trie.add(i, 0, c);
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i){
        int id;
        scanf("%d %s", &id, s);
        Q[trie.idx[id]].push_back(make_pair(ac.insert(s), i));
    }
    ac.solve();
    for (int i = 1; i <= q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
