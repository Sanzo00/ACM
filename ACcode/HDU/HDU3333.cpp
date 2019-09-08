#include <bits/stdc++.h>
#define endl '\n'
#define lowbit(x) x&(-x)
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
long long c[maxn];
int a[maxn], b[maxn];
void add(int x, int d) {
    while (x < maxn) {
        c[x] += d;
        x += lowbit(x);
    }
}
long long getsum(int x) {
    long long sum = 0;
    while (x) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
int len;
int get(int x) {
    return lower_bound(b+1, b+len, x) - b;
}
int pos[maxn];
long long ans[maxn];
struct ac{
    int l, r, id;
    bool operator < (const ac& t) const{
        return r < t.r;
    }
}Q[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    scanf("%d", &T);
    while (T--) {
        fill(pos, pos+maxn, 0);
        fill(c, c+maxn, 0);
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b+1, b+1+n);
        len = unique(b+1, b+1+n) - b;
        for (int i = 1; i <= n; ++i) a[i] = get(a[i]);
        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; ++i) {
            scanf("%d %d", &Q[i].l, &Q[i].r);
            Q[i].id = i;
        }
        sort(Q, Q + q);
        int now = 1;
        for (int i = 0; i < q; ++i) {
            int l = Q[i].l;
            int r = Q[i].r;
            int id = Q[i].id;
            while (now <= r) {
                if (pos[a[now]]) add(pos[a[now]], -b[a[now]]);
                pos[a[now]] = now;
                add(pos[a[now]], b[a[now]]);
                ++now;
            }
            ans[id] = getsum(r) - getsum(l-1);
        }
        for (int i = 0; i < q; ++i) {
            printf("%lld\n", ans[i]);
        }
    }
    return 0;
}