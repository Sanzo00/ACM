#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
int in[maxn];
int c[maxn][4];
vector<int> g[maxn];
vector<int> pp;
int Ans[maxn];
void dfs(int u, int fa) {
    pp.push_back(u);
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> c[j][i];
        }
    }
    int mm = 0;
    int start;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        in[u]++;
        in[v]++;
        mm = max(mm, in[u]);
        mm = max(mm, in[v]);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 1) start = i;
    }
    if (mm > 2) {
        cout << -1 << endl;
        return 0;
    }
    
    long long ans = 1e18;
    dfs(start, 0);
    int b[3] = {1, 2, 3};
    do{
        int tmp = 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += c[pp[i]][b[tmp]];
            tmp++;
            tmp %= 3;
        }    
        if (sum < ans) {
            ans = sum;
            tmp = 0;
            for (int i = 0; i < n; ++i) {
                Ans[pp[i]] = b[tmp];
                tmp++;
                tmp %= 3;
            }   
        }    
    }while (next_permutation(b,b+3));
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        cout << Ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
