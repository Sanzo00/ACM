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
#define maxn 4004
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

int Stack[maxn], low[maxn], dfn[maxn], inStack[maxn], belong[maxn];
int now = 0, len = 0, cnt= 0, n;
int ans[maxn];

int head[300020], pre[300020], edge[300020], tot = 1;
void add (int u, int v) {
    edge[tot] = v;
    pre[tot] = head[u];
    head[u] = tot++;
}

void tarjan(int x) {
    low[x] = dfn[x] = ++now;
    Stack[++len] = x;
    inStack[x] = 1;
    for (int i = head[x]; i; i = pre[i]) {
        int y = edge[i];
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }else if (inStack[y]) low[x] = min(low[x], low[y]);
    }
    // for (int i = 0; i < (int)g[x].size(); ++i) {
        // int y = g[x][i];
        // if (!dfn[y]) tarjan(y), low[x] = min(low[x], low[y]);
        // else if (inStack[y])    low[x] = min(low[x], low[y]);
    // }
    if (dfn[x] == low[x]) {
        ++cnt;
        int top;
        while (Stack[len] != x) {
            top = Stack[len--];
            belong[top] = cnt;
            inStack[top] = 0; 
        }
        top = Stack[len--];
        belong[top] = cnt;
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
    n = read();
    for (int i = 1, m, d; i <= n; ++i) {
        m = read();
        while (m--) {
            d = read();
            // g[i].push_back(d+n);
            add(i, d+n);
        }
    }
    for (int i = 1, d; i <= n; ++i) {
        d = read();
        // g[d+n].push_back(i);
        add(d+n, i);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i])  {
            tarjan(i);
        }

    }
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = head[i], y; j; j = pre[j]) {
            y = edge[j];
            if (belong[y] == belong[i]) ans[++sum] = y;
        }
        // for (int j = 0, y; j < (int)g[i].size(); ++j) {
            // y = g[i][j];
            // if (belong[y] == belong[i]) ans[++sum] = y; 
        // }
        out(sum);
        sort(ans+1, ans+1+sum);
        for (int i = 1; i <= sum; ++i) {
            putchar(32); out(ans[i]-n);
        }
        putchar(10);
    }
    
    return 0;
}
