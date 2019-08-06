int path[maxn], dis[maxn], head[maxn];
bool vis[maxn];
int n, m, k, cnt;
struct ac{
	int v, c, cost, pre;
}edge[maxn<<7];
void addedge(int u, int v, int c, int cost) {
	edge[cnt].v = v;
	edge[cnt].c = c;
	edge[cnt].cost = cost;
	edge[cnt].pre = head[u];
	head[u] = cnt++;
}
bool spfa (int s, int e) {
	mem(vis, false);
	mem(dis, inf);
	mem(path, -1);
	queue<int> que;
	que.push(s);
	dis[s] = 0;
	vis[s] = true;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		vis[u] = false;
		for (int i = head[u]; i != -1; i = edge[i].pre) {
			int v = edge[i].v;
			int c = edge[i].c;
			int cost = edge[i].cost;
			if (dis[v] > dis[u] + cost && c > 0) {
				dis[v] = dis[u] + cost;
				path[v] = i;
				if (!vis[v]) {
					vis[v] = true;
					que.push(v);
				}
			}
		}
	}
	if (dis[e] == inf) return false;
	else return true;
}

int MincostMaxflow(int s, int e, int &cost) {
	int maxflow = 0;
	int flow = inf;
	while (spfa(s, e)) {
		for (int i = path[e]; i != -1; i = path[edge[i^1].v])
			flow = min(flow, edge[i].c);
		for (int i = path[e]; i != -1; i = path[edge[i^1].v]) {
			edge[i].c -= flow;
			edge[i^1].c += flow;
			cost += flow * edge[i].cost;
		}
		maxflow += flow;
	}
	return maxflow;
}
