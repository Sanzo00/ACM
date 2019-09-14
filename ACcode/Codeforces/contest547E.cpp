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
        return query(rt<<1, l, mid, ql, qr, x, y) + query(rt<<1|1, mid+1, r, ql , qr, x, y);
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
