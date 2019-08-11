#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
struct ac{
    int u, v;
    double w;
    ac(){}
    ac(int _u, int _v, double _w) {u = _u, v = _v, w = _w;}
    bool operator < (const ac &t) {
        return t.w > w;
    }
}edge[maxn], p[maxn];
int pre[maxn], n, cnt;
int find(int x) {
    int t = x;
    while (pre[x] != x) {
        x = pre[x];
    }   
    while (pre[t] != x) {
        int fa = pre[t];
        pre[t] = x;
        t = fa;
    }
    return x;
}
double Kruskal(int x, int y) {
    for (int i = 0; i < cnt; ++i) {
        int u = edge[i].u;
        int v = edge[i].v;
        double w = edge[i].w;
        pre[find(u)] = find(v);
        if (find(x) == find(y)) {
            return w;
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int Case = 1;
    while (scanf("%d", &n), n) {
        cnt = 0;
        for (int i = 1; i <= n; ++i) pre[i] = i;
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &p[i].u, &p[i].v);
            for (int j = 1; j < i; ++j) {
                edge[cnt++] = ac(j, i, sqrt((p[j].u-p[i].u)*(p[j].u-p[i].u) + (p[j].v-p[i].v)*(p[j].v-p[i].v)));
            }
        }
        sort(edge, edge+cnt);
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", Case++, Kruskal(1, 2));
    }    
    return 0;
}