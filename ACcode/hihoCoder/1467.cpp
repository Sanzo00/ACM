#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 305;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
int tot, len, ts;
int low[maxn], dfn[maxn], Stack[maxn], inStack[maxn], belong[maxn]; 
vector<int> g[maxn];

void tarjan(int x) {
    Stack[len++] = x;
    inStack[x] = 1;
    low[x] = dfn[x] = ++ts;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int y = g[x][i];
        if (!dfn[y]) tarjan(y), low[x] = min(low[x], low[y]);
        else if (inStack[y]) low[x] = min(low[x], low[y]);
    }
    if (dfn[x] == low[x]) {
        tot++;
        int top;
        do{
            top = Stack[--len];
            inStack[top] = 0;
            belong[top] = tot;
        }while (top != x);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    map<char, int> mi;
    mi['m'] = 0;

    int T;
    scanf("%d", &T);
    int n, m;
    while (T--) {
        scanf("%d %d", &n, &m);
        len = ts = tot = 0;
        mem(inStack, 0);
        mem(low, 0);
        mem(Stack, 0);
        mem(belong, 0);
        mem(dfn, 0);
        for (int i = 0; i < maxn; ++i) g[i].clear();
        mi['h'] = n; 
        for (int i = 0; i < m; ++i) {
            int l, r, l1, r1; // l,r 表示一个约束条件 l1,r1 分表表示反状态
            char x, y;
            scanf(" %c%d %c%d ", &x, &l, &y, &r);
            l += mi[x];
            r += mi[y];
            l1 = l > n ? l-n : l+n;
            r1 = r > n ? r-n : r+n;
            // 建图
            g[l1].push_back(r);
            g[r1].push_back(l);
        }   
        // tarjan 
        for (int i = 1; i<= n*2; ++i) {
            if (!dfn[i]) tarjan(i);
        }
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (belong[i] == belong[i+n]) flag = 1;
        }
        puts(flag ? "BAD" : "GOOD");
    }
    
    return 0;
}