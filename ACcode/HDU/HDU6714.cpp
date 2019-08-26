#include <bits/stdc++.h>
const int maxn = 1e3 + 5;
const int mod = 998244353;
#define P pair<long long,int>
const long long inf = 1e18;
using namespace std;
long long ans;
struct ac{
    int v, c;
    bool operator < (const ac& t) {
        return v < t.v;
    }
};
int n, m;
int vis[maxn], pre[maxn];
vector<ac> g[maxn];
long long dis[maxn];
void Dij(int s) {
    fill(vis, vis+n+1, 0);
    fill(pre, pre+n+1, 0);
    fill(dis, dis+n+1, inf);
    dis[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int u = p.second;
        long long c = p.first;
        if(vis[u] || c > dis[u])   //加快速度 
            continue;
        vis[u] = 1;
        for(int i = 0; i < (int)g[u].size(); i++){
            ac t = g[u][i];
            int v = t.v;
            int cc = t.c;
            if(dis[v] > c + cc){ //更新点并加入队列 
                dis[v] = c + cc;
                if (u != s) pre[v] = max(pre[u], u);
                else pre[v] = 0;
                que.push(P(dis[v],v));
            }else if (dis[v] == c + cc) {
                int tmp = max(pre[u], u);
                if (u == s) tmp = 0;
                if (tmp < pre[v]) {
                    pre[v] = tmp;
                    que.push(P(dis[v], v));
                }
            }
        } 
    }
    for (int i = 1; i <= n; ++i) {
        ans = (ans + pre[i]) % mod;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            g[u].push_back({v, c});
            g[v].push_back({u, c});
        }
        ans = 0;
        for (int i = 1; i <= n; ++i) Dij(i);
        printf("%lld\n", ans);
    }
    return 0;
}
