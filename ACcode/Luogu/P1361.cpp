#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 1e6 + 5;
const int inf = 2e9 + 1;
const int mod = 1e9 + 7;
using namespace std;
struct Dinic{
    struct ac{
        int v, c, nex;
    }edge[maxn << 4]; // 根据题目要求计算
    int s, e;
    int head[maxn], dis[maxn], curedge[maxn], cnt;
    void init() {
        cnt = 0;
        memset(head, -1, sizeof(head));
    }
    void add(int u, int v, int c) {
        // printf("%d %d %d\n", u, v, c);
        // 正向建边
        edge[cnt] = {v, c, head[u]};
        head[u] = cnt++;
        // 反向建边, 流量为0
        edge[cnt] = {u, 0, head[v]};
        head[v] = cnt++;
    }
    bool bfs() {
        queue<int> que;
        que.push(s);
        memset(dis, 0, sizeof(dis)); // 对图进行分层
        dis[s] = 1;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i = head[u]; i != -1; i = edge[i].nex) {
                int v = edge[i].v;
                int c = edge[i].c;
                // 如果节点v已经分过层或者u->v流量为0, continue
                if (dis[v] || c == 0) continue;
                dis[v] = dis[u] + 1; // 对v进行标记并加入队列
                que.push(v);
            }
        }
        // printf("%d\n", dis[e]);
        return dis[e] > 0;  // 判断是否存在增广路，s是否能到达e
    }
    int dfs(int u, int flow) { // 增广路走到u点的最小流量为flow
        if (u == e || flow == 0) return flow;
        // 遍历u的所有出边
        for (int &i = curedge[u]; i != -1; i = edge[i].nex) { // 当前弧优化
            int v = edge[i].v;
            int c = edge[i].c;
            // 判断能否u->v增广
            if (dis[v] != dis[u] + 1 || c == 0) continue;
            int d = dfs(v, min(flow, c));
            if (d > 0) { // 找到一条增广路，修改增广路上的正反向边
                edge[i].c -= d;
                edge[i^1].c += d;
                return d;
            }            
        }
        dis[u] = -1; // // 炸点优化
        return 0;
    }
    long long dinic() {
        long long sum = 0, d;
        while (bfs()) { // 判读是否存在增广路
            for (int i = 0; i <= maxn; ++i) curedge[i] = head[i]; // copy head数组，在dfs中可以直接得到下一条没有被增广过的边
            while ((d = dfs(s, inf)) > 0) sum += d; // 多次dfs找增广路
        }
        return sum;
    }
}D;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, q, d, u, v, s, e;
    scanf("%d", &n);
    D.s = s = 0, D.e = e = n + 1;
    D.init();
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &u);
        D.add(s, i, u);
        ans += u;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v);
        D.add(i, e, v);
        ans += v;
    }
    int now = n + 2;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &q);
        scanf("%d %d", &u, &v);
        D.add(s, now, u);
        D.add(now+1, e, v);   
        ans += u + v; 
        for (int j = 0; j < q; ++j) {
            scanf("%d", &d);
            D.add(now, d, inf);
            D.add(d, now+1, inf);
        }
        now += 2;
    }
    ans = ans - D.dinic();
    printf("%lld\n", ans);
    return 0;
}