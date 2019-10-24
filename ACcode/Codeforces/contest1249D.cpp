#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
vector<pair<int,int>> g[maxn]; 
int ans[maxn], cnt[maxn], cnt2[maxn];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        cnt[v+1]--;
        g[u].push_back({v, i+1});
    }
    for (int i = 1; i < maxn; ++i) cnt[i] += cnt[i-1];
    priority_queue<pair<int,int> > que;
    vector<int> ans;
    int now = 0;
    for (int i = 1; i < maxn; ++i) {
        for (auto it : g[i]) que.push(it);
        while (cnt[i] - now > k) {
            auto f = que.top();
            que.pop();
            cnt2[f.first]++;
            ans.push_back(f.second);
            now++;
        }
        now -= cnt2[i];
    }
    cout << ans.size() << endl;
    for (auto it : ans) cout << it << " ";
    cout << endl;
    return 0;
}