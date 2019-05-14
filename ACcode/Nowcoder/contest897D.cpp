#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e3 + 1;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
struct ac{
    int v, c, pre;
}edge[maxn<<8];
int s, e;
int head[maxn<<2], dis[maxn+10], curedge[maxn<<2], cnt;
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
int n, m, k;
int odd(int x, int y) {
	return ((x + y) % 2);
}
int pos(int x, int y) {
	return (x * m + y + 1);
}
int judge(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return 1;
	if (odd(x, y)) return 1;
	return 0; 
}
int check(int x) {
	int sum = 0;
	init();
	s = 0, e = n * m + 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] < x) continue;
			sum++;
			if (odd(i, j)) {
				addedge(s, pos(i, j), 1);
				addedge(pos(i, j), s, 0);
				for (int k = -1; k <= 1; ++k) {
					for (int h = -1; h <= 1; ++h) {
						if (abs(k) + abs(h) != 1) continue;
						int ii = i + k;
						int jj = j + h;
						if (judge(ii, jj)) continue;
						addedge(pos(i, j), pos(ii, jj), inf);
						addedge(pos(ii, jj), pos(i, j), 0);
					}
				}
			}else {
				addedge(pos(i, j), e, 1);
				addedge(e, pos(i, j), 0);
			}
		}
	}
	if (sum - Dinic() >= k) return 1;
	return 0;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    scanf("%d", &T);
   	while (T--) {
   		scanf("%d%d%d", &n, &m, &k);
   		for (int i = 0; i < n; ++i) {
   			for (int j = 0; j < m; ++j) {
   				scanf("%d", &a[i][j]);
   			}
   		}
   		int l = 1, r = 1000;
   		while (l <= r) {
   			if (check(mid)) l = mid + 1;
   			else r = mid - 1;
   		}
   		printf("%d\n", r);
   	}
    return 0;
}