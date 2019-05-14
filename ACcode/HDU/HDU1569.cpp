#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 50 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
struct ac{
    int v, c, pre;
}edge[maxn<<8];
int s, e;
int head[maxn<<8], dis[maxn<<6], curedge[maxn<<8], cnt;
void init() {
    mem(head, -1);
    cnt = 0;
}
void addedge(int u, int v, int c) { // 记得双向边
    edge[cnt] = {v, c, head[u]};
    head[u] = cnt++;
}
bool bfs() {
    queue<int> que;
    que.push(s);
    mem(dis, 0);
    dis[s] = 1;
    while (!que.empty()) {
        int f = que.front();
        que.pop();
        for (int i = head[f]; i != -1; i = edge[i].pre) {
            if (dis[edge[i].v] || edge[i].c == 0) continue;
            dis[edge[i].v] = dis[f] + 1;
            que.push(edge[i].v);
        }
    }
    return dis[e] > 0; 
}

int dfs(int now, int flow) {
    if (now == e || flow == 0) return flow;
    for (int &i = curedge[now]; i != -1; i = edge[i].pre) { // 当前弧优化
        if (dis[edge[i].v] != dis[now] + 1 || edge[i].c == 0) continue;
        int d = dfs(edge[i].v, min(flow, edge[i].c));
        if (d > 0) {
            edge[i].c -= d;
            edge[i^1].c += d;
            return d;
        }            
    }
    dis[now] = -1; // // 炸点优化
    return 0;
}
int Dinic() {
    int sum = 0, d;
    while (bfs()) {
        for (int i = 0; i <= e; ++i) curedge[i] = head[i];
        while (d = dfs(s, inf)) sum += d;
    }
    return sum;
}

int a[maxn][maxn];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    while (cin >> n >> m) {
    	init();
    	int sum = 0;
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m; ++j) {
    			cin >> a[i][j];
    			sum += a[i][j];
    		}
    	}
    	s = 0, e = n * m + 1;
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m; ++j) {
    			if ((i + j) % 2 == 0) {
    				addedge(s, i*m+j+1, a[i][j]);
    				addedge(i*m+j+1, s, 0);
    				for (int k = -1; k <= 1; ++k) {
	    				for (int h = -1; h <= 1; ++h) {
	    					if (abs(k) + abs(h) != 1) continue;
	    					int x = i + k;
	    					int y = j + h;
	    					if (x < 0 || y < 0 || x >= n || y >= m) continue;
	    					if ((x + y) % 2 == 0) continue;
	    					addedge(i*m+j+1, x*m+y+1, inf);
	    					addedge(x*m+y+1, i*m+j+1, 0);
	    				}
	    			}
    			}else {
    				addedge(i*m+j+1, e, a[i][j]);
    				addedge(e, i*m+j+1, 0);
    			} 
    		}
    	}
    	int ans = sum - Dinic();
    	cout << ans << endl;
    }
    return 0;
}