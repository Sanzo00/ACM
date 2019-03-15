#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>
#define lowbit(x) (x & (-x))
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define mid ((l + r)>>1)
#define lc rt<<1
#define rc rt<<1|1
typedef long long LL;
#define maxn 2010
using namespace std;
// __int128 read() {    __int128 x = 0, f = 1;  char c = getchar(); while (c < '0' || c > '9') {        if (c == '-') f = -1;       c = getchar();  }   while (c >= '0' && c <= '9') {      x = x * 10 + c - '0';       c = getchar();  }   return x * f;}
// void print(__int128 x) { if (x < 0) {        putchar('-');       x = -x; }   if (x > 9)  print(x / 10);  putchar(x % 10 + '0');}
int read() {
    int num = 0, flag = 1;
    char c = getchar();
    while (c < '0' || c > '9')  flag = (c == '-') ? -1 : 1, c = getchar();
    while (c >= '0' && c <= '9') num = (num << 3) + (num << 1) + c - '0', c = getchar();
    return num * flag;
}
void out(int x) {
    if (x > 9)  out(x / 10);
    putchar(x % 10 + '0');
}

vector<int> g[maxn];
int used[maxn], girl[maxn];
int find(int x) {
    for (int i = 0, y; i < (int)g[x].size(); ++i) {
        y = g[x][i];
        if (used[y]) continue;
        used[y] = 1;
        if (girl[y] == 0 || find(girl[y])) {
            girl[y] = x;
            return 1;
        }
    }
    return 0;
}
int dfn[maxn], low[maxn], inStack[maxn], Stack[maxn];
int belong[maxn], ans[maxn];
int all, tot, len;
void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    inStack[x] = 1;
    Stack[++len] = x;
    for (int i = 0, y; i < (int)g[x].size(); ++i) {
        y = g[x][i];
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]); 
        }else if (inStack[y]) {
            low[x] = min(low[x], low[y]);
        }
    }

    if (dfn[x] == low[x]) {
        ++all;
        int top;
        while (Stack[len] != x) {
            top = Stack[len--];
            belong[top] = all;
            inStack[top] = 0;
        }
        top = Stack[len--];
        belong[top] = all;
        inStack[top] = 0;
    }
} 

int main() {
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N, M;

    scanf("%d", &T);
    for (int k = 1; k <= T; ++k) {
        mem(girl, 0);
        mem(dfn, 0);
        mem(inStack, 0);
        for (int i = 0; i < maxn; ++i) g[i].clear();
        
        all = len = 0;
        tot = 1;
        printf("Case #%d:\n", k);
        scanf("%d %d", &N, &M);
        for (int i = 1, t, d; i <= N; ++i) {
            scanf("%d", &t);
            while (t--) {
                scanf("%d", &d);
                g[i].push_back(d+N);
            }
        }
        int cnt = 0;
        // first_match
        for (int i = 1; i <= N; ++i) {
            mem(used, 0);
            cnt += find(i);
        }
        int num = N + M;
        // add_node
        for (int i = M - cnt; i; --i) {
            ++num;
            for (int j = 1; j <= M; ++j) {
                g[num].push_back(j + N);
            }
        }
        // add_node
        for (int i = N - cnt; i; --i) {
            ++num;
            for (int j = 1; j <= N; ++j) {
                g[j].push_back(num);
            }
        }

        int L = N+M+M-cnt;
        mem(girl, 0);
        for (int i = 1; i <= N; ++i) {
            mem(used, 0);
            find(i);
        }
        for (int i = N+M+1; i <= L; ++i) {
            mem(used, 0);
            find(i);
        }

        // build_graph
        for (int i = N+1; i <= N+M; ++i) {
            g[i].push_back(girl[i]);
        }
        for (int i = L+1; i <= num; ++i) {
            g[i].push_back(girl[i]);
        }
        for (int i = 1; i <= N; ++i) {
            if (dfn[i]) continue;
            tarjan(i);
        }

        for (int i = 1; i <= N; ++i) {
            int sum = 0;
            for (int j = 0, y; j < (int)g[i].size(); ++j) {
                y = g[i][j];
                if (belong[y] == belong[i] && y >= N+1 && y <= N+M) ans[sum++] = y;
            }
            sort(ans, ans+sum);
            printf("%d", sum);
            for (int j = 0; j < sum; ++j) {
                printf(" %d", ans[j]-N);
            }
            puts("");
        }
    }
    return 0;
}
