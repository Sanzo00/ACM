## CF-547E(Mike and Friends)

#### 题意

$N$个串,每次询问区间$[L,R]$中有多少子串$S_i$

#### 思路

1. 把$N$个串合成一个长字符串,对这个长字符串求后缀数组,包含$S_i$的子串的$height$连续排列,可以用线段树维护height对应原串的位置,每次询问变成找区间$[L',R'](lcp(L,R) >= S_i)$中有多少符合位置在$[L,R]$中
2. 对$N$个串建$AC$自动机,$fail$树上的每个父节点是当前节点的最长后缀,子串$S_i$的数量就是$S_i$的子树的大小,在求出$fail$树和$dfs$序之后,对于区间$[L,R]$的限制可以用主席树或是离线处理+树状数组处理

```cpp
#include <bits/stdc++.h>
const int maxn = 4e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
char s[maxn], t[maxn];
int idx[maxn], start[maxn], len[maxn];
struct ac{
    int cntA[maxn], cntB[maxn], A[maxn], B[maxn];
    int Sa[maxn], tSa[maxn], height[maxn], Rank[maxn];
    int n, dp[maxn][21];
    void init(char *buf, int len) {
        n = len;
        for (int i = 0; i < 256; ++i) cntA[i] = 0;
        for (int i = 1; i <= n; ++i) cntA[(int)buf[i]]++;
        for (int i = 1; i < 256; ++i) cntA[i] += cntA[i-1];
        for (int i = n; i >= 1; --i) Sa[cntA[(int)buf[i]]--] = i;
        Rank[Sa[1]] = 1;
        for (int i = 2; i <= n; ++i) {
            Rank[Sa[i]] = Rank[Sa[i-1]];
            if (buf[Sa[i]] != buf[Sa[i-1]]) Rank[Sa[i]]++;
        }
        for (int l = 1; Rank[Sa[n]] < n; l <<= 1) {
            for (int i = 0; i <= n; ++i) cntA[i] = 0;
            for (int i = 0; i <= n; ++i) cntB[i] = 0;
            for (int i = 1; i <= n; ++i) {
                cntA[A[i] = Rank[i]]++;
                cntB[B[i] = (i+l<=n) ? Rank[i+l]:0]++;
            }
            for (int i = 1; i <= n; ++i) cntB[i] += cntB[i-1];
            for (int i = n; i >= 1; --i) tSa[cntB[B[i]]--] = i;
            for (int i = 1; i <= n; ++i) cntA[i] += cntA[i-1];
            for (int i = n; i >= 1; --i) Sa[cntA[A[tSa[i]]]--] = tSa[i];
            Rank[Sa[1]] = 1;
            for (int i = 2; i <= n; ++i) {
                Rank[Sa[i]] = Rank[Sa[i-1]];
                if (A[Sa[i]] != A[Sa[i-1]] || B[Sa[i]] != B[Sa[i-1]]) Rank[Sa[i]]++;
            }
        }
        for (int i = 1, j = 0; i <= n; ++i) {
            if (j) --j;
            int tmp = Sa[Rank[i] - 1];
            while (i+j <= n  && tmp+j <= n && buf[i+j] == buf[tmp+j]) ++j;
            height[Rank[i]] = j;
        }
    }  
    void st() {
        for (int i = 1; i <= n; ++i)  dp[i][0] = height[i];
        for (int j = 1; j <= log2(n); ++j) {
            for (int i = 1; i + (1<<j)-1 <= n; ++i) {
                dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
            }
        }        
    }
    int rmq(int l, int r) {
        if (l == r) return inf;
        l++;
        int len = r - l + 1;
        int x = log2(len);
        return min(dp[l][x], dp[r-(1<<x)+1][x]);
    }
    vector<int> g[maxn<<2];
    void build(int rt, int l, int r) {
        for (int i = l; i <= r; ++i) g[rt].emplace_back(idx[Sa[i]]);
        sort(g[rt].begin(), g[rt].end());
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(rt<<1, l, mid);
        build(rt<<1|1, mid+1, r);
    } 
    int getL(int len, int t, int l, int r) {
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (rmq(mid, t) >= len) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
    int getR(int len, int t, int l, int r) {
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (rmq(t, mid) >= len) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
    int query(int rt, int l, int r, int ql, int qr, int x, int y) {
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) {
            int L = lower_bound(g[rt].begin(), g[rt].end(), x) - g[rt].begin();
            int R = upper_bound(g[rt].begin(), g[rt].end(), y) - g[rt].begin();
            return R - L;        
        }
        int mid = (l + r) >> 1;
        int sum = 0;
        if (mid >= ql) sum += query(rt<<1, l, mid, ql, qr, x, y);
        if (mid < qr) sum += query(rt<<1|1, mid+1, r, ql , qr, x, y);
        return sum;
    }
    void solve(int q) {
        build(1, 1, n);
        while (q--) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            int L = getL(len[k], Rank[start[k]], 1, Rank[start[k]]);
            int R = getR(len[k], Rank[start[k]], Rank[start[k]], n);
            printf("%d\n", query(1, 1, n, L, R, l, r));
        }
    }
}S;
int main() {
    int n, m, now = 0;
    scanf("%d %d", &n, &m);
    s[now] = '|';
    for (int i = 1; i <= n; ++i) {
        scanf("%s", t);
        len[i] = strlen(t);
        start[i] = now+1;
        for (int j = 0; j < len[i]; ++j) {
            s[++now] = t[j];
            idx[now] = i;
        }
        s[++now] = '|';
        idx[now] = 0;
    }
    s[now+1] = 0;
    S.init(s, now);
    S.st();
    S.solve(m);
    return 0;
}
```
```cpp
#include <bits/stdc++.h>
const int maxn = 5e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
vector<int> g[maxn];
struct Trie{
    int nex[maxn][26], fail[maxn], end[maxn];
    int pre[maxn];
    int L[maxn], R[maxn], cnt;
    int root, p;
    inline int newnode() {
        for (int i = 0; i < 26; ++i) nex[p][i] = -1;
        return p++;
    }
    inline void init() {
        cnt = p = 0;
        root = newnode();
    }
    void insert(int id, char *buf) {
        int now = root;
        for (int i = 0; buf[i]; ++i) {
            if (nex[now][buf[i]-'a'] == -1) nex[now][buf[i]-'a'] = newnode();
            pre[nex[now][buf[i]-'a']] = now;
            now = nex[now][buf[i]-'a'];
        }
        end[id] = now;
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
            g[fail[now]].push_back(now);
            for (int i = 0; i < 26; ++i) {
                if (nex[now][i] == -1) nex[now][i] = nex[fail[now]][i];
                else {
                    fail[nex[now][i]] = nex[fail[now]][i];
                    que.push(nex[now][i]);
                }
            }
        }
    }
    void dfs(int x) {
        L[x] = ++cnt;
        for (auto it : g[x]) dfs(it);
        R[x] = ++cnt;
    }
}S;
struct ac{
    int l, r, id;
};
int c[maxn];
void add(int x, int d) {
    while (x < maxn) {
        c[x]++;
        x += x&(-x);
    }
}
int getsum(int x) {
    int ans = 0;
    while(x) {
        ans += c[x];
        x -= x&(-x);
    }
    return ans;
}
int ans[maxn];
vector<ac> Q1[maxn], Q2[maxn];
char s[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    scanf("%d %d", &n, &m);
    S.init();
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        S.insert(i, s);
    }
    S.build();
    S.dfs(0);
    for (int i = 1,l,r,k; i <= m; ++i) {
        scanf("%d %d %d", &l, &r, &k);
        Q1[l].push_back({S.L[S.end[k]], S.R[S.end[k]], i});
        Q2[r].push_back({S.L[S.end[k]], S.R[S.end[k]], i});
    }
    for (int i = 1; i <= n; ++i) {
        int now = S.end[i];
        while (now) {
            add(S.L[now], 1);
            now = S.pre[now];
        }
        for (int j = 0; j < (int)Q1[i+1].size(); ++j) {
            int l = Q1[i+1][j].l;
            int r = Q1[i+1][j].r;
            int id = Q1[i+1][j].id;
            ans[id] -= getsum(r) - getsum(l-1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (int)Q1[i].size(); ++j) {
            int l = Q1[i][j].l;
            int r = Q1[i][j].r;
            int id = Q1[i][j].id;
            ans[id] += getsum(r) - getsum(l-1);
        }
    }
    fill(c, c+maxn, 0);
    for (int i = n; i >= 1; --i) {
        int now = S.end[i];
        while (now) {
            add(S.L[now], 1);
            now = S.pre[now];
        }
        for (int j = 0; j < (int)Q2[i-1].size(); ++j) {
            int l = Q2[i-1][j].l;
            int r = Q2[i-1][j].r;
            int id = Q2[i-1][j].id;
            ans[id] -= getsum(r) - getsum(l-1);
        }
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
```