#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int pre[maxn];
int find (int x) {
    return (pre[x] == x) ? x : pre[x] = find(pre[x]);
    int tx = x;
    while (x != pre[x]) {
        x = pre[x];
    }
    int t;
    while (pre[tx] != x) {
        t = pre[tx];
        pre[tx] = x;
        tx = t;
    }
    return x;
}
vector<int> g[maxn];
int d[maxn], a[maxn], c[maxn];
char b[maxn];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, tn;
    while (cin >> n >> m) {
        tn = n;
        mem(d, 0);
        for (int i = 0; i <= n; ++i) pre[i] = i, g[i].clear();
        for (int i = 0; i < m; ++i) {
            cin >> a[i] >> b[i] >> c[i];
            if (b[i] == '=') {
                int fx = find(a[i]);
                int fy = find(c[i]);
                if (fx == fy) continue;
                tn--;
                if (fx > fy) swap(fx, fy);
                pre[fy] = fx;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (b[i] == '=') continue;
            int fx = find(a[i]);
            int fy = find(c[i]);
            if (b[i] == '<') {
                g[fy].push_back(fx);
                d[fx]++;
            }else {
                g[fx].push_back(fy);
                d[fy]++;
            }
        }
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (d[i] == 0 && find(i) == i) {
                que.push(i);
            }
        }
        int flag = 0;
        while (!que.empty()) {
            if (que.size() > 1) flag = 1;
            int f = que.front();
            que.pop();
            tn--;
            for (int i = 0, x; i < (int)g[f].size(); ++i) {
                x = g[f][i];
                if (--d[x] == 0) que.push(x);
            }
        }
        if (tn) cout << "CONFLICT\n";
        else if (flag) cout << "UNCERTAIN\n";
        else cout << "OK\n";
    }

    return 0;
}