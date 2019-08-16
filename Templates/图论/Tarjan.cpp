// 强联通分量
int dfn[maxn], low[maxn], Stack[maxn], inStack[maxn], belong[maxn], in[maxn], ts, cnt, len;
void init(int n) {
    for (int i = 1; i <= n; ++i) g[i].clear();
    ts = cnt = len = 0;
    fill(dfn, dfn+n+1, 0);
    fill(inStack, inStack+n+1, 0);
}
void tarjan(int u) {
    dfn[u] = low[u] = ++ts;
    inStack[u] = 1;
    Stack[len++] = u;
    for (int i = 0; i < (int)g[u].size(); ++i) {
        int v = g[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if (inStack[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        cnt++;
        while (1) {
            int top = Stack[--len];
            belong[top] = cnt;
            inStack[top] = 0;
            if (top == u) break;
        }
    }
}
for (int i = 1; i <= n; ++i) {
    if (dfn[i]) continue;
    tarjan(i);
}