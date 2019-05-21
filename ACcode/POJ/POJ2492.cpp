#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <numeric>
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
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int pre[maxn], n, m;
void init () {
    for (int i = 0; i <= n*2; ++i) {
        pre[i] = i;
    }
}
int find(int x) {
    return (x == pre[x]) ? x : pre[x] = find(pre[x]);
    // int tmp = x, fa;
    // while (x != pre[x]) {
    //     x = pre[x];
    // }
    // while (tmp != x) {
    //     fa = pre[tmp];
    //     pre[tmp] = x;
    //     tmp = fa;
    // }
    // return x;
}
int id(int x) {return (x + n);}
void join(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;
    if (fx > fy) swap(fx, fy);
    pre[fy] = fx;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int T, now = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        init();
        printf("Scenario #%d:\n", ++now);
        for (int i = 0, u,v; i < m; ++i) {
            scanf("%d %d", &u, &v);
            join(u, id(v));
            join(id(u), v);
        }
        int flag = 0;
        for (int i = 1; i <= n && !flag; ++i) {
            if (find(i) == find(id(i))) flag = 1;
        }
        if (flag) puts("Suspicious bugs found!");
        else puts("No suspicious bugs found!");
        puts("");
    }
    return 0;
}