#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
struct SAM{
    int trans[maxn<<1][26], slink[maxn<<1], maxlen[maxn<<1];
    // 用来求endpos
    int indegree[maxn<<1], endpos[maxn<<1], rank[maxn<<1], ans[maxn<<1];
    long sum[maxn<<1];
    int last, now, root, len;
    inline void newnode (int v) {
        maxlen[++now] = v;
    }
    inline void init() {
        root = now = 1;
        memset(trans, 0, sizeof(trans));
    }
    inline void extend(int c) {
        if (trans[last][c]) { // 广义自动机 节点合并 节省空间
            int p = last, np = trans[last][c];
            if (maxlen[last] + 1 == maxlen[np]) last = np;
            else {
                int q = trans[p][c];
                newnode(maxlen[p]+1);
                int nq = now;
                memcpy(trans[nq], trans[q], sizeof(trans[q]));
                slink[nq] = slink[q];
                slink[q] = last = nq;
                while (p && trans[p][c] == q) {
                    trans[p][c] = nq;
                    p = slink[p];
                }
            }
            return;
        }
        newnode(maxlen[last] + 1); // 新建节点
        int p = last, np = now;
        // 更新trans
        while (p && !trans[p][c]) { // last的slink只想新节点
            trans[p][c] = np;
            p = slink[p];
        }
        if (!p) slink[np] = root; 
        else { // slink中存在节点有到c的边
            int q = trans[p][c];
            if (maxlen[p] + 1 != maxlen[q]) { // 判断是否为同一个endpos
                newnode(maxlen[p] + 1); // 将q点拆出nq，使得maxlen[p] + 1 == maxlen[q]
                int nq = now;
                memcpy(trans[nq], trans[q], sizeof(trans[q]));
                slink[nq] = slink[q];
                slink[q] = slink[np] = nq;
                while (p && trans[p][c] == q) {
                    trans[p][c] = nq;
                    p = slink[p];
                } 
            }else slink[np] = q;
        }
        last = np;
        // 初始状态为可接受状态
        endpos[np] = 1;
    }
    inline void insert(char *buf) {
        len = strlen(buf);
        last = 1;
        for (int i = 0; i < len; ++i) extend(buf[i] - 'a'); // extend(s[i] - '1');
    }
    int cnt[maxn], vis[maxn];
    long long dp[maxn];
    inline void Topsort() {
        for (int i = 1; i <= now; ++i) indegree[maxlen[i]]++;
        for (int i = 1; i <= now; ++i) indegree[i] += indegree[i-1];
        for (int i = 1; i <= now; ++i) rank[indegree[maxlen[i]]--] = i;
    }
    inline void init_string(char *buf, int num) {
        int tnow = 1;
        for (int i = 0; buf[i]; ++i) {
            tnow = trans[tnow][buf[i] - 'a'];
            int tmp = tnow;
            while (tmp && vis[tmp] != num) {
                vis[tmp] = num;
                cnt[tmp]++;
                tmp = slink[tmp];
            }
        }
    }
    inline void init_dp(int k) {
        Topsort();
        for (int i = 1; i <= now; ++i) {
            int tnow = rank[i];
            if (cnt[tnow] >= k) dp[tnow] = maxlen[tnow] - maxlen[slink[tnow]];
            if (slink[tnow]) dp[tnow] += dp[slink[tnow]];
        }   
    }
    inline void solve(char *buf) {
        long long ans = 0;
        int tnow = 1;
        for (int i = 0; buf[i]; ++i) {
            tnow = trans[tnow][buf[i] - 'a'];
            ans += dp[tnow];
        }
        printf("%lld ", ans);
    }
}sam;
char s[maxn], t[maxn];
int pos[maxn], length[maxn];
int main() {
    int n, k, now = 0;
    scanf("%d%d", &n, &k);
    sam.init();
    for (int i = 1; i <= n; ++i) {
        scanf("%s", t);
        length[i] = strlen(t);
        pos[i] = now;
        for (int j = 0; j < length[i]; ++j) {
            s[now++] = t[j];
        }
        s[now++] = 0;
        sam.insert(s+pos[i]);
    }
    for (int i = 1; i <= n; ++i) sam.init_string(s+pos[i], i);
    sam.init_dp(k);
    for (int i = 1; i <= n; ++i) sam.solve(s+pos[i]);
    return 0;
}