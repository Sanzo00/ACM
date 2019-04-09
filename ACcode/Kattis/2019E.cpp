#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 5e5 + 5;

vector<int> g[maxn];
int d[maxn], vis[maxn];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0, x,y; i < m; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        d[x]++; d[y]++;
    }
    queue<int> que;
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 1){
          que.push(i);
          vis[i] = 1;  
        } 
    }
    while (!que.empty()) {
        int f = que.front();
        que.pop();
        for (int i : g[f]) {
            if (vis[i]) continue;
            if (--d[i] == 1) {
                que.push(i);
                vis[i] = 1; 
            }
        }
    }
    mem(vis, 0);
    for (int i = 1; i <= n; ++i) {
        if (d[i] > 1) {
            vis[i] = 1;
            que.push(i);
        }
    }
    while (!que.empty()) {
        int f = que.front();
        que.pop();
        for (int j : g[f]) {
            if (vis[j]) continue;
            vis[j] = 1;
            que.push(j);
        }
    }

    vector<P> ans;
    for (int i = 1; i <= n; ++i) {
        for (int j : g[i]) {
            if (vis[i] && d[i] > 1 && d[j] == 1 ) 
                ans.push_back(make_pair(i, j));
            if (!vis[i] && g[i].size() == 1)
                ans.push_back(make_pair(i, j));
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it.first << " " << it.second << "\n";
    }
}