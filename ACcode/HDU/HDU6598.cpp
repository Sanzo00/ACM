#include <bits/stdc++.h>
#define endl '\n'
const int maxn = 5e2 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
struct Dinic{
    struct ac{
        int v, c, nex;
    }edge[maxn << 6]; // 根据题目要求计算
    int s, e;
    int head[maxn], dis[maxn], curedge[maxn], cnt;
    void init() {
        cnt = 0;
        memset(head, -1, sizeof(head));
    }
    void add(int u, int v, int c) {
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
            for (int i = 0; i <= e; ++i) curedge[i] = head[i]; // copy head数组，在dfs中可以直接得到下一条没有被增广过的边
            while ((d = dfs(s, inf)) > 0) sum += d; // 多次dfs找增广路
        }
        return sum;
    }
}D;
int L[maxn], R[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, s, e;
    while (scanf("%d %d", &n, &m) != EOF) {
        D.s = s = 0, D.e = e = n + 1;
        D.init();
        int u, v, a, b, c;
        long long ans = 0;
        fill(L, L+n+1, 0);
        fill(R, R+n+1, 0);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d %d %d", &u, &v, &a, &b, &c);
            ans += a + b + c;
            D.add(u, v, a + c - 2*b);
            D.add(v, u, a + c - 2*b);
            L[u] += b + c;
            L[v] += b + c;
            R[u] += a + b;
            R[v] += a + b;
        }
        for (int i = 1; i <= n; ++i) {
            D.add(s, i, L[i]);
            D.add(i, e, R[i]);
        }
        ans = ans * 2 - D.dinic();
        printf("%lld\n", ans / 2);
    }
    return 0;
}
