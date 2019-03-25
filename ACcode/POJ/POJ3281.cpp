#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <time.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 405;
const int inf = 0x3f3f3f3f;

int g[maxn][maxn];
int N, F, D;
int vis[maxn], pre[maxn], tmp[maxn];

bool bfs (int s, int e) {
    mem(vis, 0);
    mem(pre, -1);
    vis[s] = 1;
    pre[s] = s;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int f = que.front();
        que.pop();
        // cout <<f << endl;
        for (int i = 1; i <= e; ++i) {
            // cout << i << endl;
            if (vis[i] || !g[f][i]) continue;
            pre[i] = f;
            tmp[i] = g[f][i];
            vis[i] = 1;
            que.push(i);
            if (i == e) return 1;
        }
    }
    return 0;
}

int EK(int s, int e) {
    int ans = 0;
    while (bfs(s, e)) {
        int MIN = inf;
        int i = e;
        while (i != s) {
            MIN = min(MIN, g[pre[i]][i]);
            i = pre[i];
        }
        i = e;
        while (i != s) {
            g[pre[i]][i] -= MIN;
            g[i][pre[i]] += MIN;
            i = pre[i];
        }
        ans += MIN;
    }
    return ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);   
    cin >> N >> F >> D;
    int n1 = F;
    int n2 = n1 + N;
    int n3 = n2 + N;
    int s = 0, e = n3 + D + 1;
    for (int i = 1, fi, di; i <= N; ++i) {
        cin >> fi >> di;
        for (int j = 0, d; j < fi; ++j) {
            cin >> d;
            g[d][n1+i] = 1;
        }
        for (int j = 0, d; j < di; ++j) {
            cin >> d;
            g[n2+i][n3+d] = 1;
        }
    }
    for (int i = 1; i <= F; ++i) {
        g[s][i] = 1;
    }
    for (int i = 1; i <= D; ++i) {
        g[i+n3][e] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        g[n1+i][n2+i] = 1;
    }

    int ans = EK(s, e);
    cout << ans << endl;

    return 0;
}