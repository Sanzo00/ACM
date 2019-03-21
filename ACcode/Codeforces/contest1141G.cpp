#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#include <time.h>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
const int maxn = 200005;
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;

int D;
int degree[maxn];
vector<int> g[maxn];
map<int, int> cnt;
map<P, int> mp;
int ans[maxn];

void dfs(int x, int fa, int f) {
    int color = 0;
    for (auto it : g[x]) {
        if (it == fa) continue;
        if (color == f) {
            color = (color + 1) % D;
        }
        ans[mp[P(x, it)]] = color;
        dfs(it, x, color);
        color = (color + 1) % D;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;

    for (int i = 1, l, r; i < n; ++i) {
        cin >> l >> r;
        degree[l]++;
        degree[r]++;
        
        g[l].push_back(r);
        g[r].push_back(l);
       
        mp[P(l, r)] = i; // 记录编号
        mp[P(r, l)] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cnt[degree[i]]++; // 统计相同度数的节点个数
    }
    int unfair = n; // 需要的颜色个数
    for (auto it : cnt) {
        if (unfair > k) {
            D = it.first;
            unfair -= it.second;
        }
    }
    dfs(1, 0, -1);    
    cout << D << endl;
    for (int i = 1; i < n; ++i) {
        cout << ans[i]+1 << " ";
    }
    cout << endl;
    return 0;
}